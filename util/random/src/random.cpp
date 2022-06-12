//
// random.cpp
//
// Copyright(c) 2021 Sourav Batabyal
//

#include "random.h"

long long deccenc::util::Random::get_current_time_micros() {
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}
