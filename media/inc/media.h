//
// media.h
// Foundational class for a media element.
//
// Copyright(c) 2021 Sourav Batabyal <mailme.souravbatabyal@gmail.com>
//

#pragma once

#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <iostream>

#include "component.h"
#include "media_par.h"

namespace deccenc {
class Media : public Component {
private:
	long long id_;	// media id
	std::string handle_;	// how the media is to be accessed
	media_handle_type handle_type_;	// media handle type
	media_io_type io_type_;	// media io type
private:
	void parse_media_handle_type();
public:
	Media(deccenc::media_io_type io_type, std::string handle);
	virtual ~Media();
	const long long& get_media_id();
	const std::string& get_media_handle();
	std::string get_media_handle_type_str();
	std::string get_media_handle_io_type_str();
};
}

#endif 
