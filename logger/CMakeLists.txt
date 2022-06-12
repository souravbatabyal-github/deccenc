add_library(logger 
	src/logger.cpp
)
target_include_directories(logger
	PUBLIC inc)
target_link_libraries(logger
	PUBLIC component
	PUBLIC traceme)
