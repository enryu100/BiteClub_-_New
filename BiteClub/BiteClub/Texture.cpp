#include "Texture.h"
#include "TextureLoader.h"

using namespace std;

bool Texture::loadData(string texFile){
	return loader::loadTexture(texFile.c_str(), texData, &width, &height, &channels);
}

void Texture::freeData(){
	loader::freeTexture(texData);
}