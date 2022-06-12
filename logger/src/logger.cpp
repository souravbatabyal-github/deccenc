// logger.cpp
// Generic logging component

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
