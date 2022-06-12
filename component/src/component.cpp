//
// component.cpp
// Definitions of the component class.
//
// Copyright(c) 2021 Sourav Batabyal <mailme.souravbatabyal@gmail.com>
//

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
