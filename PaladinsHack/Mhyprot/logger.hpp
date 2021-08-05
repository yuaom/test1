#pragma once
#include <iostream>

#define LOG_ERROR() \
	logger::log2("[!] failed at in %s:%d, (0x%lX)\n", __FILE__, __LINE__, GetLastError())

namespace logger
{
	template <typename ... T>
	__forceinline void log2(const char* format, T const& ... args)
	{
		printf(format, args ...);
	}
}