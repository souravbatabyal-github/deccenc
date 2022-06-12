add_executable(media_test
	src/main.cpp
)
target_link_libraries(media_test
	PUBLIC logger
	PUBLIC component
	PUBLIC traceme
	PUBLIC media)
