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
  flogger_test.c
  flogger test code.
*/
#include <stddef.h>
#include <limits.h>
#include "flogger.h"

/* Testcase Functions */
/* Test Case - 1: logger name is NULL - ok or not.*/
void tc_1()
{
    FLoggerSpace *space = NULL;
    logger_init(NULL, LogLevel_Err, (void**)&space);
    flogger_set_fname((void*)space, "out.log");
    logger_log((void*)space, LogLevel_Dbg, "tc1: test log - debug");
    logger_log((void*)space, LogLevel_Crt, "tc1: test log - critical");
    logger_close((void**)&space);
}
/* Test Case - 2: logger dataspace is NULL - ok or not.*/
void tc_2()
{
    logger_init(NULL, LogLevel_Err, NULL);
    flogger_set_fname(NULL, "out.log");
    logger_log(NULL, LogLevel_Dbg, "tc2: test log - debug");
    logger_log(NULL, LogLevel_Crt, "tc2: test log - critical");
    logger_close(NULL);
}
/* Test Case - 3: logger name, dataspace is not NULL - ok or not.*/
void tc_3()
{
    FLoggerSpace *space = NULL;
    logger_init("tc-3", LogLevel_Err, (void**)&space);
    flogger_set_fname((void*)space, "out.log");
    logger_log((void*)space, LogLevel_Dbg, "tc3: test log - debug");
    logger_log((void*)space, LogLevel_Crt, "tc3: test log - critical");
    logger_close((void**)&space);
}
/* Test Case - 4: bulk log.*/
void tc_4()
{
    FLoggerSpace *space = NULL;
    logger_init("tc-4", LogLevel_Dbg, (void**)&space);
    flogger_set_fname((void*)space, "out.log");
    long i = 10000;
    while(i-- > 0)
    {
        logger_log((void*)space, LogLevel_Dbg, "tc4: test log - debug");
        logger_log((void*)space, LogLevel_Crt, "tc4: test log - critical");
    }
    flogger_set_fname((void*)space, "out1.log");
    i = 10000;
    while(i-- > 0)
    {
        logger_log((void*)space, LogLevel_Dbg, "tc4: test log - debug");
        logger_log((void*)space, LogLevel_Crt, "tc4: test log - critical");
    }
    logger_close((void**)&space);
}

/* Main */
int main()
{
    tc_1();
    tc_2();
    tc_3();
    tc_4();

    return 0;
}
