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
  flogger.c
  File based log implementation, using logger_api.h API.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flogger.h"
#include "t_utility.h"
void logger_init(char *name, int baselevel, void **space)
{
    if (!name)
        return;
    FLoggerSpace **flspace = (FLoggerSpace**)space;
    if (!flspace)
        return;
    if (*flspace)
        logger_close(space);

    FLoggerSpace* flspace_tmp = (FLoggerSpace *)malloc(sizeof(FLoggerSpace));
    if (!flspace_tmp)
        return;

    flspace_tmp->file_name_ = NULL;
    flspace_tmp->h_file_ = NULL;
    flspace_tmp->lspace_ = NULL;

    LoggerSpace *lspace_tmp = (LoggerSpace *)malloc(sizeof(LoggerSpace));
    if (!lspace_tmp)
    {
        free(flspace_tmp);
        flspace_tmp = NULL;
    }
    lspace_tmp->name_ = strdup(name);
    lspace_tmp->level_ = baselevel;
    flspace_tmp->lspace_ = lspace_tmp;

    *flspace = flspace_tmp;
}
void logger_setlevel(void *space, int level)
{
    FLoggerSpace *flspace = (FLoggerSpace*)space;
    if (flspace)
    {
        LoggerSpace *lspace = flspace->lspace_;
        lspace->level_ = level;
    }
}
void logger_log(void *space, int level, char* log)
{
    FLoggerSpace *flspace = (FLoggerSpace*)space;
    if (!flspace)
        return;
    LoggerSpace *lspace = flspace->lspace_;
    if (!lspace)
        return;
    if (!log)
        return;
    if (level >= lspace->level_)
    {
        char htime[80] = {0};
        get_current_time_readable(htime, (size_t)80);
        fprintf(flspace->h_file_, "\n[%s][%s][%s]", htime, lspace->name_, log);
    }
}
void logger_close(void **space)
{
    FLoggerSpace **flspace = (FLoggerSpace**)space;
    if (flspace && *flspace)
    {
        LoggerSpace *lspace = (*flspace)->lspace_;
        if (lspace)
        {
            free(lspace->name_);
            lspace->name_ = NULL;
            lspace->level_ = LogLevel_Dbg;
            free(lspace);
        }
        (*flspace)->lspace_ = NULL;
        if ((*flspace)->file_name_)
            free((*flspace)->file_name_);
        (*flspace)->file_name_ = NULL;
        if ((*flspace)->h_file_)
            fclose((*flspace)->h_file_);
        (*flspace)->h_file_ = NULL;
        free(*flspace);
    }
}
void flogger_set_fname(void *space, char *fname)
{
    if (!fname)
        return;
    FLoggerSpace *flspace = (FLoggerSpace*)space;
    if (flspace)
    {
        if (flspace->file_name_)
            free(flspace->file_name_);
        flspace->file_name_ = NULL;
        if (flspace->h_file_)
            fclose(flspace->h_file_);
        flspace->h_file_ = NULL;
        flspace->file_name_ = strdup(fname);
        flspace->h_file_ = fopen(flspace->file_name_, "a");
    }
}
