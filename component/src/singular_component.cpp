//
// component.cpp
// Definitions of the component class.
//
// Copyright(c) 2021 Sourav Batabyal <mailme.souravbatabyal@gmail.com>
//

#include "singular_component.h"
#include "traceme.h"

deccenc::SingularComponent* deccenc::SingularComponent::ref_ = NULL;

deccenc::SingularComponent::SingularComponent(const char* const name) : Component(name) {
	info("SingularComponent constructor created for %s", name_);
}

deccenc::SingularComponent::~SingularComponent() {
	info("SingularComponent destructed for %s", name_);
}
