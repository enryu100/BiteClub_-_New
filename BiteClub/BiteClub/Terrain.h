/*
* Terrain.h
* Author: Alfred Malone
* Purpose: to encapsulate and manage the data required to render a terrain in 3D space.
*/
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

namespace terrain{
	class Terrain{
	public:
		Terrain();
		~Terrain();

		bool loadHeightfield(std::string fileName);
		void setScale(float x, float y, float z);
		const std::vector<unsigned char> getTerrainData();
		int getTerrainSize();
		float getXScale();
		float getYScale();
		float getZScale();

	private:
		std::unique_ptr<std::vector<unsigned char>> terrainData;
		float xScale;
		float yScale;
		float zScale;
		int terrainSize;

		bool inBounds(int xPos, int zPos);
		float getHeight(int xPos, int zPos);
		unsigned char getHeightColour(int xPos, int zPos);
	};
}
