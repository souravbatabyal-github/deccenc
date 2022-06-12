//
// random.h
// Some random things generator.
//
// Copyright(c) 2021 Sourav Batabyal
//

#pragma once
#ifndef _RANDOM_HH
#define _RANDOM_HH

#include <iostream>
#include <chrono>

namespace deccenc{
namespace util {
class Random {
public:
	/**
	 * Returns current time in microseconds
	 */
	static long long get_current_time_micros();
};
}
}

#endif
