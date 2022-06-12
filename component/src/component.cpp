// component.cpp
// Definitions of the component class.

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

#include "component.h"
#include "traceme.h"

deccenc::Component::Component(const char* const name) 
: name_(NULL) {
	info("Component constructor create request for %s", name);
	if (name) {
		set_name((char*)name);
		info("Component constructor create success for %s", name_);
	} else {
		info("Component constructor create failure for %s", name_);
	}
}

deccenc::Component::Component(long long l_name_ll) 
: name_(NULL) {
	info("Component constructor create request for %lld", l_name_ll);
	std::string name_str(std::to_string(l_name_ll));
	char* name = (char*)name_str.data();
	set_name(name);
	info("Component constructor create success for %s", name_);
}

deccenc::Component::~Component() {
	info("Component destructing for %s", name_);
	if (name_) {
		free(name_);
	}
	name_ = NULL;
	info("Component destructed.");
}

void deccenc::Component::set_name(char* name) {
	int32_t l_len = strlen(name);
	name_ = (char*)malloc((l_len + 1) * sizeof(char));
	memcpy(name_, name, l_len);
	*(name_ + l_len) = '\0';
}
