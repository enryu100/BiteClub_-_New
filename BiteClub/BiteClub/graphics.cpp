#include "graphics.h"

using namespace std;
using namespace graphics;
using namespace events;

GraphicsEngine::GraphicsEngine(){
	window = nullptr;
	screenWidth = 1024;
	screenHeight = 720;
	textureMap = false;
}

GraphicsEngine::~GraphicsEngine(){
}

void GraphicsEngine::init(vector<string> modelFiles){
	SDL_GLContext context;

	for(int index = 0; index < modelFiles.size(); index++){
		Model newModel;
		if(newModel.loadData(modelFiles[index])){
			models.push_back(newModel);
			cout << modelFiles[index] << " has been loaded!" << endl;
		}
	}

	// Initialise SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create window. Hard-coded values will be changed when everything works.
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);

	if(window == nullptr)
		exit(1); // A bit brash, but gets the job done

	context = SDL_GL_CreateContext(window);

	if(context == nullptr)
		exit(1);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, screenWidth, screenHeight);
	gluPerspective(45.0, 1.0, 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void GraphicsEngine::display(double camX, double camY, double camZ, double lookX, double lookY, double lookZ, double upX, double upY, double upZ){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(camX, camY, camZ, lookX, lookY, lookZ, upX, upY, upZ);

	drawTerrain();
	drawModels();

	SDL_GL_SwapWindow(window);
}

gameEvent GraphicsEngine::pollEvents(){
	SDL_Event eventSDL;
	gameEvent eventGame;

	while(SDL_PollEvent(&eventSDL)){
		eventGame.hasEvents = true;

		switch(eventSDL.type){
		case SDL_QUIT:
			eventGame.hasQuit = true;
			break;
		case SDL_MOUSEMOTION:
			eventGame.mouseX = eventSDL.motion.x;
			eventGame.mouseY = eventSDL.motion.y;
			break;
		case SDL_KEYDOWN:
			eventGame.keysPressed.push_back((char)eventSDL.key.keysym.sym);
			eventGame.keyDown = true;
			break;
		default:
			break;
		}
	}

	return eventGame;
}

void GraphicsEngine::setScales(float scal, float xzscal){
	scale = scal;
	xzscale = xzscal;
}

void GraphicsEngine::getHeightfieldData(const vector<unsigned char> data){
	heightfieldData = data;
}

void GraphicsEngine::drawTerrain(){
	// Square root because the actual size is all of the elements. This is, of course, assuming that the heightfield has the same dimensions for width and height.
	int terrainSize = (int)sqrt((double)heightfieldData.size());
	unsigned char heightColour;
	float height;
	float texLeft, texBottom, texTop;

	//Stuff for texturing (incomplete?)
	if(textureMap){
		glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, texture.getID());
	}

	for(int zVal = 0; zVal < terrainSize; zVal++){
		glBegin(GL_TRIANGLE_STRIP);
		for(int xVal = 0; xVal < terrainSize; xVal++){

			//calc texture coords
			texLeft = (float)xVal/terrainSize;
			texBottom = (float)zVal/terrainSize;
			texTop = (float)(zVal + 1)/terrainSize;

			heightColour = heightfieldData.at((zVal * terrainSize) + xVal);
			glColor3ub(heightColour, heightColour, heightColour);
			glTexCoord2f(texLeft, texBottom);
			height = (float)(heightColour * scale) - 150.0f;
			glVertex3f((float)xVal * xzscale, height, (float)zVal * xzscale);

			if((zVal + 1) < terrainSize){
				heightColour = heightfieldData.at(((zVal + 1) * terrainSize) + xVal);
				glColor3ub(heightColour, heightColour, heightColour);
				glTexCoord2f(texLeft, texTop);
				height = (float)(heightColour * scale) - 150.0f;
				glVertex3f((float)xVal * xzscale, height, (float)(zVal + 1) * xzscale);
			}
		}
		glEnd();
	}
}

void GraphicsEngine::drawModels(){
	ModelData modelInfo;
	types::Vector3D modelPos;

	for(int index = 0; index < models.size(); index++){
		modelInfo = models[index].getData();
		modelPos = models[index].getModelPos();

		glBegin(GL_TRIANGLE_STRIP);
		for(int vertIndex = 0; vertIndex < modelInfo.vertices.size(); vertIndex++){
			glVertex3f(modelInfo.vertices[vertIndex].x + modelPos.x, modelInfo.vertices[vertIndex].y + modelPos.y, modelInfo.vertices[vertIndex].z + modelPos.z); 
		}
		glEnd();
	}
}

bool Model::loadData(string modelFile){
	return loader::loadObj(modelFile.c_str(), data.vertices, data.uvs, data.normals);
}