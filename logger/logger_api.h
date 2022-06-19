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
logger_api.h
Logger usage API.
*/
#define debug(fmt, ...)		\
	printf("\n F[%s] f[%s] l[%d]" fmt, __FILE__, __func__, __LINE__, ##__VA_ARGS__);	\
	fflush(stdout);
#define info(fmt, ...)		\
	printf(" INFO: f[%-20s] l[%-3d] " fmt "\n", __func__, __LINE__, ##__VA_ARGS__);	\
	fflush(stdout);
typedef struct _loggerspace_
{
    char* name_;
    int level_;
} LoggerSpace;
enum _loglevel_
{
    LogLevel_Dbg = 1,   // log level debug
    LogLevel_Inf,       // log level info
    LogLevel_Wrn,       // log level warning
    LogLevel_Err,       // log level error
    LogLevel_Crt,       // log level critical
    LogLevel_Ftl        // log level fatal
};
void logger_init(char *name, int baselevel, LoggerSpace **out_space);
void logger_setlevel(LoggerSpace *space, int level);
void logger_log(LoggerSpace *space, int level, char* log);
void logger_close(LoggerSpace **space);
