#pragma once

#include <string>

class Texture{
	public:
		Texture(){texData = NULL;};
		~Texture(){freeData();};

		bool loadData(std::string texFile);
		void freeData();
		const unsigned char* getTexture(){return texData;};
		const int getWidth(){return width;};
		const int getHeight(){return height;};
		const int getChannels(){return channels;};
		int texID;

	private:
		unsigned char* texData;
		int width;
		int height;
		int channels;
};