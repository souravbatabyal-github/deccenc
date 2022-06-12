// media.h
// Foundational class for a media element.
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
