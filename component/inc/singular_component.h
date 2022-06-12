//
// singular_component.h
// Foundational class.
//
// Copyright(c) 2021 Sourav Batabyal <mailme.souravbatabyal@gmail.com>
//

#pragma once

#ifndef _SINGULAR_COMPONENT_H_
#define _SINGULAR_COMPONENT_H_

#include <iostream>
#include "component.h"

namespace deccenc {
class SingularComponent : public Component {
public:
	SingularComponent(const char* const name);
	virtual ~SingularComponent();
	static SingularComponent* ref_;
};
}

#endif 
