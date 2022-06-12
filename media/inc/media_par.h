//
// media_par.h
// Some media parameters.
//
// Copyright(c) 2021 Sourav Batabyal
//

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
