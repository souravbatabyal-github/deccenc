add_library(media 
	src/media.cpp
)
target_include_directories(media
	PUBLIC inc)
target_link_libraries(media
	PUBLIC traceme
	PUBLIC component
	PUBLIC util)
