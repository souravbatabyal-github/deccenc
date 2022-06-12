//
// component.h
// Foundational class.
//
// Copyright(c) 2021 Sourav Batabyal <mailme.souravbatabyal@gmail.com>
//

#pragma once

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <iostream>
#include <cstring>

namespace deccenc {
class Component {
public:
	/**
	 * The component name
	 */
	char* name_;
private:
	void set_name(char* name);
public:
	Component(const char* const name);
	Component(long long name);
	virtual ~Component();
};
}

#endif 
