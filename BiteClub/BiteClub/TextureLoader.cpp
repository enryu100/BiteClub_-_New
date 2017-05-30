#include "TextureLoader.h"
#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

using namespace loader;
using namespace std;
using namespace types;

bool loader::loadTexture(const char* path, unsigned char* texData, int* width, int* height, int* channels){
	texData = stbi_load(path, width, height, channels, 0);

	if(texData == NULL)
		return false;
	else
		return true;
}

void loader::freeTexture(unsigned char* texData){
	stbi_image_free(texData);
}