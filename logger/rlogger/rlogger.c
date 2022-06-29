/**
MIT License

Copyright (c) 2022 Sourav Batabyal

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/**
  rlogger.c
  Rolling log implementation, using logger_api.h API.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rlogger.h"
#include "t_utility.h"
#include "t_string.h"
void* rlog_write(void *data)
{
    RLoggerSpace *rlspace = (RLoggerSpace*)data;
    if (!rlspace)
        return NULL;
    FILE *f_from = fopen(rlspace->file_name_, "r");
    if (!f_from)
        return NULL;

    char htime[80] = {0};
    get_current_time_readable(htime, (size_t)80);
    size_t rlspace_file_len = strlen(rlspace->file_name_);
    char *f_to_name = (char*)malloc(rlspace_file_len + strlen(htime) + 6); // + _, .log
    int nc = sprintf(f_to_name, "%s_%s.log", rlspace->file_name_, htime);
    f_to_name[nc] = '\0';
    char *f_to_name_final = replace_word(f_to_name, " ", "-");
    free(f_to_name);

    FILE *f_to = fopen(f_to_name_final, "w");
    free(f_to_name_final);
    if (!f_to)
    {
        fclose(f_from);
        return NULL;
    }
    char c;
    do{
      c = getc(f_from);
      putc(c, f_to);
    }while(c != EOF);
    fclose(f_to);
    fclose(f_from);

    rlspace->h_file_ = fopen(rlspace->file_name_, "w");
    fclose(rlspace->h_file_);
    rlspace->bytes_written_ = 0;
    rlspace->time_written_ms_start_ = 0;
    rlspace->time_written_ms_end_ = 0;
    rlspace->h_file_ = fopen(rlspace->file_name_, "a");
    free(rlspace->thread_);
    rlspace->thread_ = NULL;

    return NULL;
}
void logger_init(char *name, int baselevel, void **space)
{
    if (!name)
        return;
    RLoggerSpace **rlspace = (RLoggerSpace**)space;
    if (!rlspace)
        return;
    if (*rlspace)
        logger_close(space);

    RLoggerSpace* rlspace_tmp = (RLoggerSpace *)malloc(sizeof(RLoggerSpace));
    if (!rlspace_tmp)
        return;

    rlspace_tmp->file_name_ = NULL;
    rlspace_tmp->h_file_ = NULL;
    rlspace_tmp->lspace_ = NULL;
    rlspace_tmp->bytes_written_ = 0;
    rlspace_tmp->time_written_ms_start_ = 0;
    rlspace_tmp->time_written_ms_end_ = 0;
    rlspace_tmp->size_limit_bytes_ = 0;
    rlspace_tmp->time_limit_ms_ = 0;
    rlspace_tmp->thread_ = NULL;

    LoggerSpace *lspace_tmp = (LoggerSpace *)malloc(sizeof(LoggerSpace));
    if (!lspace_tmp)
    {
        free(rlspace_tmp);
        rlspace_tmp = NULL;
    }
    lspace_tmp->name_ = strdup(name);
    lspace_tmp->level_ = baselevel;
    rlspace_tmp->lspace_ = lspace_tmp;

    *rlspace = rlspace_tmp;
}
void logger_setlevel(void *space, int level)
{
    RLoggerSpace *rlspace = (RLoggerSpace*)space;
    if (rlspace)
    {
        LoggerSpace *lspace = rlspace->lspace_;
        lspace->level_ = level;
    }
}
void logger_log(void *space, int level, char* log)
{
    RLoggerSpace *rlspace = (RLoggerSpace*)space;
    if (!rlspace)
        return;
    LoggerSpace *lspace = rlspace->lspace_;
    if (!lspace)
        return;
    if (!log)
        return;
    if (level >= lspace->level_)
    {
        char htime[80] = {0};
        get_current_time_readable(htime, (size_t)80);
        int bytes = fprintf(rlspace->h_file_, "\n[%s][%s][%s]", htime, lspace->name_, log);
        if (0 < bytes)
        {
            rlspace->bytes_written_ += (size_t)bytes;
            long long current_t = get_current_time_millis();
            if (!rlspace->time_written_ms_start_)
            {
                rlspace->time_written_ms_start_ = current_t;
                rlspace->time_written_ms_end_ = 0;
            }
            else
                rlspace->time_written_ms_end_ = current_t;

            // check limit
            if ((rlspace->size_limit_bytes_ && rlspace->bytes_written_ >= rlspace->size_limit_bytes_) || (rlspace->time_limit_ms_ && rlspace->time_written_ms_start_ && rlspace->time_limit_ms_ <= (rlspace->time_written_ms_end_ - rlspace->time_written_ms_start_)))
            {
                // spawn thread
                if (rlspace->thread_)
                {
                    // error, wait for the thread to stop.
                }
                else
                {
                    rlspace->thread_ = (pthread_t*)malloc(sizeof(pthread_t));
                    if (pthread_create(rlspace->thread_, NULL, (void*)&rlog_write, (void*)rlspace))
                        printf("\npthread create error");
                }
            }
        }
    }
}
void logger_close(void **space)
{
    RLoggerSpace **rlspace = (RLoggerSpace**)space;
    if (rlspace && *rlspace)
    {
        LoggerSpace *lspace = (*rlspace)->lspace_;
        if (lspace)
        {
            free(lspace->name_);
            lspace->name_ = NULL;
            lspace->level_ = LogLevel_Dbg;
            free(lspace);
        }
        (*rlspace)->lspace_ = NULL;
        if ((*rlspace)->file_name_)
            free((*rlspace)->file_name_);
        (*rlspace)->file_name_ = NULL;
        if ((*rlspace)->h_file_)
            fclose((*rlspace)->h_file_);
        (*rlspace)->h_file_ = NULL;
        free(*rlspace);
    }
}
void rlogger_set_fname(void *space, char *fname)
{
    if (!fname)
        return;
    RLoggerSpace *rlspace = (RLoggerSpace*)space;
    if (rlspace)
    {
        if (rlspace->file_name_)
            free(rlspace->file_name_);
        rlspace->file_name_ = NULL;
        if (rlspace->h_file_)
            fclose(rlspace->h_file_);
        rlspace->h_file_ = NULL;
        rlspace->file_name_ = strdup(fname);
        rlspace->h_file_ = fopen(rlspace->file_name_, "a");
    }
}
void rlogger_set_byte_limit(void *space, size_t maxbytes)
{
    RLoggerSpace *rlspace = (RLoggerSpace*)space;
    if (rlspace)
        rlspace->size_limit_bytes_ = maxbytes;
}
void rlogger_set_time_limit_ms(void *space, long long maxmillis)
{
    RLoggerSpace *rlspace = (RLoggerSpace*)space;
    if (rlspace)
        rlspace->time_limit_ms_ = maxmillis;
}
