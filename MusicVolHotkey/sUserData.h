#pragma once

#include "dti_types.h"
#include <functional>

#pragma execution_character_set("utf-8")

struct sUserData {
	static inline sUserData* Get() { return *(sUserData**)0x145011710; } //ver 15.22
	template<class _T> _T& at(size_t _Off) { return *(_T*)(u64(this) + _Off); }
};

