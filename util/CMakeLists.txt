add_library(util 
	random/src/random.cpp
)
target_include_directories(util
	PUBLIC random/inc)
