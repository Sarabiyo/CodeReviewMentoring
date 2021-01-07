#pragma once

#include <iostream>

#define M_LOG(fmt,...) printf(fmt,##__VA_ARGS__); \
	putchar('\n')