// main.cpp
// Logger test module

#include <iostream>
#include "logger.h"
#include "traceme.h"

int main() {
	deccenc::Logger* l_p_logger = (deccenc::Logger*)deccenc::Logger::create_instance("logger_test");
	info("%s", "Here is my code");
	info("%s", "Here is my code");
	info("%s", "Here is my code");
	info("%s", "Here is my code");
	deccenc::Logger::delete_instance();
	return 0;
}
