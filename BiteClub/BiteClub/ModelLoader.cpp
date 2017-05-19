#include "ModelLoader.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace loader;
using namespace std;
using namespace types;

bool loader::loadObj(const char* path, vector<Vector3D> & outVertices, vector<Vector2D> & outUVs, vector<Vector3D> & outNormals){
	vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	vector<Vector3D> tempVertices, tempNormals;
	vector<Vector2D> tempUVs;
	string lineHeader;
	Assimp::Importer modelLoader;

	const aiScene* scene = modelLoader.ReadFile(path, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);
	if(!scene)
		return false;

	if(scene->mNumMeshes > 0){
		for(int i = 0; i < scene->mNumMeshes; i++){
			for(int j = 0; j < scene->mMeshes[i]->mNumVertices; j++){
				outVertices.push_back(Vector3D(scene->mMeshes[i]->mVertices[j].x, scene->mMeshes[i]->mVertices[j].y, scene->mMeshes[i]->mVertices[j].z));
			}
		}
	}

	int texWidth, texHeight;

	if(scene->mNumTextures > 0){
		for(int i = 0; i < scene->mNumTextures; i++){
			texWidth = scene->mTextures[i]->mWidth;
			if(scene->mTextures[i]->mHeight = 0){
				texHeight = 1;
			}
			else{
				texHeight = scene->mTextures[i]->mHeight;
			}

			for(int j = 0; j < (texWidth * texHeight); j++){

			}
		}
	}
	/*
	ifstream file(path, ios::in);
	if(!file)
		return false;

	while(getline(file, lineHeader)){		

		if(lineHeader.substr(0, 2) == "v "){
			Vector3D vertex;

			istringstream str(lineHeader.substr(2));
			str >> vertex.x;
			str >> vertex.y;
			str >> vertex.z;
			tempVertices.push_back(vertex);
		}
		else if(lineHeader.substr(0, 3) == "vt "){
			Vector2D uv;

			istringstream str(lineHeader.substr(2));
			str >> uv.x;
			str >> uv.y;
			tempUVs.push_back(uv);
		}
		else if(lineHeader.substr(0, 3) == "vn "){
			Vector3D normal;

			istringstream str(lineHeader.substr(2));
			str >> normal.x;
			str >> normal.y;
			str >> normal.z;
			tempNormals.push_back(normal);
		}
		else if(lineHeader.substr(0, 2) == "f "){
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

			// UV indices aren't working in the test model, so they've been removed.

			istringstream str(lineHeader.substr(2));
			str >> vertexIndex[0];
			str.ignore(1, '/');
			//str >> uvIndex[0];
			str.ignore(1, '/');
			str >> normalIndex[0];

			str >> vertexIndex[1];
			str.ignore(1, '/');
			//str >> uvIndex[1];
			str.ignore(1, '/');
			str >> normalIndex[1];

			str >> vertexIndex[2];
			str.ignore(1, '/');
			//str >> uvIndex[2];
			str.ignore(1, '/');
			str >> normalIndex[2];

			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			//uvIndices.push_back(uvIndex[0]);
			//uvIndices.push_back(uvIndex[1]);
			//uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
	}

	file.close();

	for(int index = 0; index < vertexIndices.size() && index < tempVertices.size(); index++){
		if(vertexIndices[index] - 1 >= 0)
			outVertices.push_back(tempVertices[vertexIndices[index] -1]);
	}

	/*
	for(int index = 0; index < uvIndices.size() && index < tempUVs.size(); index++){
		if(uvIndices[index] - 1 >= 0)
			outUVs.push_back(tempUVs[uvIndices[index] -1]);
	}
	

	for(int index = 0; index < normalIndices.size() && index < tempNormals.size(); index++){
		if(normalIndices[index] - 1 >= 0)
			outNormals.push_back(tempNormals[normalIndices[index] -1]);
	}
	*/
	return true;
}