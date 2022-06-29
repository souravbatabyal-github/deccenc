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
  syslogger.c
  Syslog implementation, using logger_api.h API.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include "syslogger.h"
#include "t_utility.h"
void logger_init(char *name, int baselevel, void **space)
{
    if (!name)
        return;
    LoggerSpace **lspace = (LoggerSpace**)space;
    if (!lspace)
        return;
    *lspace = NULL;
    *lspace = (LoggerSpace *)malloc(sizeof(LoggerSpace));
    if (*lspace)
    {
        (*lspace)->name_ = strdup(name);
        (*lspace)->level_ = baselevel;
        //setlogmask (LOG_UPTO ((*lspace)->level_));
        openlog ((*lspace)->name_, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);
    }
}
void logger_setlevel(void *space, int level)
{
    LoggerSpace *lspace = (LoggerSpace*)space;
    if (lspace)
    {
        lspace->level_ = level;
        setlogmask (LOG_UPTO (lspace->level_));
    }
}
void logger_log(void *space, int level, char* log)
{
    LoggerSpace *lspace = (LoggerSpace*)space;
    if (!lspace)
        return;
    if (!log)
        return;
    if (level >= lspace->level_)
    {
        /*
        char htime[80] = {0};
        get_current_time_readable(htime, (size_t)80);
        printf("\n[%s][%s][%s]", htime, lspace->name_,log);
        */
        syslog (level, "%s", log);
    }
}
void logger_close(void **space)
{
    LoggerSpace **lspace = (LoggerSpace**)space;
    if (lspace && *lspace)
    {
        closelog();
        free((*lspace)->name_);
        (*lspace)->name_ = NULL;
        (*lspace)->level_ = LogLevel_Dbg;
        free(*lspace);
        (*lspace) = NULL;
    }
}
