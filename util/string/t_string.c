// t_string.c

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

#include "t_string.h"

char* replace_word(const char* s, const char* old_w, const char* new_w)
{
    char* result;
    int i, cnt = 0;
    int new_wlen = strlen(new_w);
    int old_wlen = strlen(old_w);
 
    // Counting the number of times old word occur in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], old_w) == &s[i]) {
            cnt++;
 
            // Jumping to index after the old word.
            i += old_wlen - 1;
        }
    }
 
    // Making new string of enough length
    result = (char*)malloc(i + cnt * (new_wlen - old_wlen) + 1);
 
    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, old_w) == s) {
            strcpy(&result[i], new_w);
            i += new_wlen;
            s += old_wlen;
        }
        else
            result[i++] = *s++;
    }
 
    result[i] = '\0';
    return result;
}
