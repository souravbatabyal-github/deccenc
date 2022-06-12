// media.cpp
// Definitions of the media class.
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

#include "media.h"
#include "traceme.h"
#include "random.h"

deccenc::Media::Media(deccenc::media_io_type io_type, std::string handle) 
: Component(deccenc::util::Random::get_current_time_micros()), 
	id_(std::stoll(name_)),
	io_type_(io_type),
	handle_(handle)
{
	info("Media constructor create request for %s, %lld", handle_.data(), id_);
	parse_media_handle_type();
}

deccenc::Media::~Media() {
	info("Media destructing for %s", name_);
	info("Media destructed.");
}

const long long& deccenc::Media::get_media_id() {
	return id_;
}

const std::string& deccenc::Media::get_media_handle() {
	return handle_;
}

std::string deccenc::Media::get_media_handle_type_str() {
	switch (handle_type_) {
		case deccenc::media_handle_type::file:
			return "file";
		case deccenc::media_handle_type::rtsp:
			return "rtsp";
		case deccenc::media_handle_type::rtmp:
			return "rtmp";
		case deccenc::media_handle_type::none:
			return "none";
	}
}

void deccenc::Media::parse_media_handle_type() {
	char* p_handle = (char*)handle_.data();
	if (strstr(p_handle, deccenc::media_handle_type_identifier::file)) {
		handle_type_ = deccenc::media_handle_type::file;
	} else if (strstr(p_handle, deccenc::media_handle_type_identifier::rtsp)) {
		handle_type_ = deccenc::media_handle_type::rtsp;
	} else if (strstr(p_handle, deccenc::media_handle_type_identifier::rtmp)) {
		handle_type_ = deccenc::media_handle_type::rtmp;
	}
}

std::string deccenc::Media::get_media_handle_io_type_str() {
	switch (io_type_) {
		case deccenc::media_io_type::input:
			return "input";
		case deccenc::media_io_type::filter:
			return "filter";
		case deccenc::media_io_type::output:
			return "output";
		case deccenc::media_io_type::none:
			return "none";
	}
}
