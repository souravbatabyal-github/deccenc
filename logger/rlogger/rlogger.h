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
  rlogger.h
  Rolling log implementation, using logger_api.h API.
*/
#include <pthread.h>
#include "logger_api.h"
typedef struct _rloggerspace_
{
    LoggerSpace *lspace_;                   // logger space
    char        *file_name_;                // log file name
    FILE        *h_file_;                   // log file handle

    size_t      bytes_written_;             // how much bytes written to the file
    long long   time_written_ms_start_;     // data since time written in file
    long long   time_written_ms_end_;       // data of how much time written in file

    size_t      size_limit_bytes_;          // after how much bytes, logs will be rolled to new file
    long long   time_limit_ms_;             // after every n millis logs will be rolled to new file

    pthread_t   *thread_;                    // rotating log writer thread
} RLoggerSpace;
void rlogger_set_fname(void *space, char *fname);
void rlogger_set_byte_limit(void *space, size_t maxbytes);
void rlogger_set_time_limit_ms(void *space, long long maxmillis);
