#include "MainGame.h"
//Known Bugs: Keyboard input messes up the lookat position, this is due to the get state getting any input, so pressinga  button sets the camera back to like whatever I set the default as
//Need to change how input works in regards to mouse movement
using namespace graphics;
using namespace terrain;

MainGame::MainGame(void){
	currentState = GameState::PLAY;
	mouseSpeed = 0.004f;
}

MainGame::~MainGame(void){

}

void MainGame::run(string initFile){
	initSystems(initFile);
	gameLoop();
}

void MainGame::initSystems(string initFile){
	string terrainFile, terrainTexFile, fileString = "modelFile";
	int numModels;
	std::vector<string> modelFiles;

	fileLoader.Load(initFile.c_str());
	cout << "init" << endl;

	terrainFile = fileLoader.Read_Variable_String("terrainFile");
	cout << "terrain" << endl;

	terrainTexFile = fileLoader.Read_Variable_String("terrainTexFile");
	cout << "terrain texture" << endl;

	numModels = fileLoader.Read_Variable_Int("numModels");
	for(int index = 0; index < numModels; index++){
		int modelNum = index + 1;

		modelFiles.push_back(fileLoader.Read_Variable_String((fileString + to_string(modelNum)).c_str()));
	}

	gameTerrain.loadHeightfield(terrainFile);
	if(gameTerrain.loadTerrainTexture(terrainTexFile))
		cout << "Texture success!" << endl;
	else
		cout << "FAILURE" << endl;
	gameTerrain.setScale(10.0f, 0.5f, 10.0f);

	graphicsEng.init(modelFiles);
	graphicsEng.getHeightfieldData(gameTerrain.getTerrainData());
	graphicsEng.getHeightfieldTexture(gameTerrain.getTerrainTexture());
	graphicsEng.setScales(gameTerrain.getYScale(), gameTerrain.getXScale());

	// Temp camera init. Do this from a file later.
	player.setMoveSpeed(10.0);
	player.setRotateSpeed(100.0);
	mouse1 = 0;
	mouse2 = 0;
}


float MainGame::HeightMapTracking(){
	float height;
	types::Matrix4x4 temp = player.getViewMatrix();
	height = gameTerrain.getHeight((int)temp.columns[3].x, (int)temp.columns[3].z);
	return height;
}

void MainGame::processInput(){
	events::gameEvent newEvent = graphicsEng.pollEvents();
	float xChange = 0.0f, zChange = 0.0f, pitchChange = 0.0f, yawChange = 0.0f;
	float yChange = HeightMapTracking();
	float move =0;
	if(newEvent.hasEvents){
		// Change camera view (mouse move)
		//yawChange = newEvent.mouseX - gameEvnt.mouseX;
		//pitchChange = newEvent.mouseY - gameEvnt.mouseY;
		//mouse change is being set really high when a key is pressed-1512 for 1?
		//mouse change 2 is 2360
		//pressing a ket sets mouseX and Y to 0?

		float mousechange1 = (float)(1024.0f/2.0f - gameEvnt.mouseX);
		float mousechange2 = (float)(720.0f/2.0f - gameEvnt.mouseY);
		//float mousechange1 = gameEvnt.mouseX - newEvent.mouseX;
		//float mousechange2 =  gameEvnt.mouseY-newEvent.mouseY;

		//old1 = temp1;
		//old2 = temp2;
		//Problem exists here, is to do with mousechange
		if(gameEvnt.mouseX !=0){
			mouse1 += mouseSpeed * float( mousechange1);
			mouse2 += mouseSpeed * float(  mousechange2);
		}

		// Perform action (button/key press)
		if(newEvent.keyDown){
			for(unsigned index = 0; index < newEvent.keysPressed.size(); index++){
				std::cout << newEvent.keysPressed.at(index);
				switch(newEvent.keysPressed.at(index)){
				case 'w':
					zChange = 1.0f;
					xChange = 1.0f;
					break;
				case 's':
					zChange = -1.0f;
					xChange = -1.0f;
					break;
				case 'a':
					move = -1;
					break;
				case 'd':
					move =1;
					break;
				case 27:
					exit(0);
					break;
				default:
					break;
				}
			}
			std::cout << std::endl;
		}
		
		player.transformView(xChange, yChange, zChange, mouse1, mouse2, move);

		// Test code
		types::Matrix4x4 temp = player.getViewMatrix();
		std::cout << "Look-at point: " << temp.columns[2].x << ", " << temp.columns[2].y << ", " << temp.columns[2].z << std::endl
				  << "Right: " << temp.columns[0].x << ", " << temp.columns[0].y << ", " << temp.columns[0].z << std::endl
				  << "Position: " << temp.columns[3].x << ", " << temp.columns[3].y << ", " << temp.columns[3].z << std::endl
				  << "mouse X" << gameEvnt.mouseX<<std::endl
				  << "mouse Y" << gameEvnt.mouseY<<std::endl;

		if(newEvent.hasQuit)
			currentState = GameState::EXIT;

		gameEvnt = newEvent;
	}
	//gameEvnt = newEvent;
}




void MainGame::gameLoop(){
	types::Matrix4x4 view;

	while(currentState != GameState::EXIT){
		view = player.getViewMatrix();
		processInput();
		graphicsEng.display(view.columns[3].x, view.columns[3].y, view.columns[3].z,
						    (view.columns[2].x + view.columns[3].x), (view.columns[2].y + view.columns[3].y), (view.columns[2].z + view.columns[3].z),
							view.columns[1].x, view.columns[1].y, view.columns[1].z);
	}
}
