//
// logger.cpp
// Generic logging component
//
// Copyright(c) 2021 Sourav Batabyal <mailme.souravbatabyal@gmail.com>
//

#include <stdio.h>
#include <stdarg.h>

#include "logger.h"
#include "traceme.h"

deccenc::SingularComponent* deccenc::Logger::create_instance(const char* const name) {
	info("%s", "Logger::CreateInstance()");
	if (!ref_) {
		ref_ = new Logger(name);
	}
	return ref_;
}
void deccenc::Logger::delete_instance() {
	info("%s", "Logger::DeleteInstance()");
	if (ref_) {
		delete ref_;
	}
	ref_ = NULL;
}

deccenc::Logger::Logger(const char* const name) : SingularComponent(name) {
	info("Creating Logger Constructor for %s", name_);
}

deccenc::Logger::~Logger() {
	info("Destructing Logger Constructor for %s", name_);
}
