/**
* ObjLoader.h
*
* Author: Alfred Malone
* Date: 27/4/2017
*
* This simply holds a very simple function for loading .obj files, which was made using code
* from http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/ and
* https://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Load_OBJ.
*/
#pragma once

#include <vector>
#include "Types.h"

namespace loader{
	/**
	* @brief Loads a .obj file and retrieves information pertaining to 3D models.
	* @param path - The path of the file to be opened
	* @param outVertices - A list of vertex co-ordinates for a 3D model
	* @return bool - true if the file loaded properly, false if not
	*
	* loadObj is a very simple (and error-prone) loader for models from .obj files. The file
	* is opened and the data retrieved, then put into the list of data passed by reference
	* from a model object.
	*/
	bool loadObj(const char* path, std::vector<types::Vector3D> & outVertices);
}
