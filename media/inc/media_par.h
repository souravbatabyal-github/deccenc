// media_par.h
// Some media parameters.
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

#pragma once

#ifndef _MEDIA_PAR_HH_
#define _MEDIA_PAR_HH_

#include <iostream>

namespace deccenc {

// media_io_type
enum class media_io_type {
	none = 0,
	input = 1,
	filter = 2,
	output = 3
};
// media_handle_type
enum class media_handle_type {
	none = 0,
	file = 1, 
	rtsp = 2, 
	rtmp = 3
};
// media handle type identifiers
struct media_handle_type_identifier {
	static constexpr char* file = "file://";
	static constexpr char* rtsp = "rtsp://";
	static constexpr char* rtmp = "rtmp://";
};
}

#endif
