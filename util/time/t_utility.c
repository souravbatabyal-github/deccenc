// t_utility.c

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

#include "t_utility.h"
#include <sys/time.h>
#include <stddef.h>
#include <time.h>

long long get_current_time_millis()
{
    struct timeval tm;
    gettimeofday(&tm, NULL);    
    long long milliseconds = tm.tv_sec*1000LL + tm.tv_usec/1000; // calculate milliseconds
    return milliseconds;
}
void get_current_time_readable(char *buf, size_t sizeof_buf)
{
    if (NULL != buf && sizeof_buf > 0)
    {
        struct tm ts;
        time_t now;
        time(&now);
        ts = *localtime(&now);
        strftime(buf, sizeof_buf, "%Y-%m-%d %H:%M:%S %Z", &ts);
    }
}
