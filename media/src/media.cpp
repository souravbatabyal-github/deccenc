//
// media.cpp
// Definitions of the media class.
//
// Copyright(c) 2021 Sourav Batabyal <mailme.souravbatabyal@gmail.com>
//

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
