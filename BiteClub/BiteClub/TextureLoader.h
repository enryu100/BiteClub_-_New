#pragma once

#include <vector>
#include "Types.h"

namespace loader{
	bool loadTexture(const char* path, unsigned char* texData, int* width, int* height, int* channels);
	void freeTexture(unsigned char* texData);
}