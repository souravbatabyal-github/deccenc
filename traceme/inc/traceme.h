//
// trace.h
// Component to trace a line/function
//
// Copyright(c) 2021 Sourav Batabyal <mailme.souravbatabyal@gmail.com>
//

#pragma once

#ifndef _TRACEME_HH_
#define _TRACEME_HH_

#include <iostream>

#define debug(fmt, ...)		\
	printf("\n F[%s] f[%s] l[%d]" fmt, __FILE__, __func__, __LINE__, ##__VA_ARGS__);	\
	fflush(stdout);

#define info(fmt, ...)		\
	printf(" INFO: f[%-20s] l[%-3d] " fmt "\n", __func__, __LINE__, ##__VA_ARGS__);	\
	fflush(stdout);


#endif
