add_library(component 
	src/component.cpp
	src/singular_component.cpp
)
target_include_directories(component
	PUBLIC inc)
target_link_libraries(component
	PUBLIC traceme)
