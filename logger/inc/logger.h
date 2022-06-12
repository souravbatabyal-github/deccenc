//
// logger.h
// Generic logging component
//
// Copyright(c) 2021 Sourav Batabyal <mailme.souravbatabyal@gmail.com>
//

#pragma once

#ifndef _LOGGER_HH_
#define _LOGGER_HH_

#include <iostream>
#include "singular_component.h"

namespace deccenc {
class Logger : public SingularComponent {
private:
	Logger(const char* const name);
	virtual ~Logger();
public:
	static SingularComponent* create_instance(const char* const name);
	static void delete_instance();
};
}

#endif

