//
// main.cpp
// Logger test module
//

#include <iostream>
#include "logger.h"
#include "traceme.h"
#include "media.h"
#include "media_par.h"

int main() {
	std::string media_handle("file://asgjkahsdbfhjasdgb");
	deccenc::Media* l_p_media = new deccenc::Media(deccenc::media_io_type::input, media_handle);

	info("Media ID: %lld", l_p_media->get_media_id());
	info("Media Handle: %s", l_p_media->get_media_handle().data());
	info("Media Handle Type: %s", l_p_media->get_media_handle_type_str().data());
	info("Media Handle I/O Type: %s", l_p_media->get_media_handle_io_type_str().data());


	delete l_p_media;
	return 0;
}
