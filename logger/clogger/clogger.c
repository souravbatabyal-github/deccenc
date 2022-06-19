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
  clogger.c
  Console log implementation, using logger_api.h API.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "t_utility.h"
void logger_init(char *name, int baselevel, LoggerSpace **out_space)
{
    if (NULL != out_space && NULL != name)
    {
        *out_space = NULL;
        *out_space = (LoggerSpace *)malloc(sizeof(LoggerSpace));
        if (NULL != *out_space)
        {
            (*out_space)->name_ = strdup(name);
            (*out_space)->level_ = baselevel;
        }
    }
}
void logger_setlevel(LoggerSpace *space, int level)
{
    if (NULL != space)
        space->level_ = level;
}
void logger_log(LoggerSpace *space, int level, char* log)
{
    if (NULL == log)
        return;
    char htime[80] = {0};
    get_current_time_readable(htime, (size_t)80);
    if (NULL != space)
    {
        if (level >= space->level_)
            printf("\n[%s][%s][%s]", htime, space->name_,log);
    }
    else
        printf("\n[%s][%s]", htime, log);
}
void logger_close(LoggerSpace **space)
{
    if (NULL != space && NULL != *space)
    {
        free((*space)->name_);
        (*space)->name_ = NULL;
        (*space)->level_ = LogLevel_Dbg;
        free(*space);
        (*space) = NULL;
    }
}
