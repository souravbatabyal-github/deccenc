add_executable(logger_test
	src/main.cpp
)
target_link_libraries(logger_test
	PUBLIC logger
	PUBLIC component
	PUBLIC traceme)
