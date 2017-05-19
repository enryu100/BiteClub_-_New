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
	string terrainFile, fileString = "modelFile1";
	int numModels;
	std::vector<string> modelFiles;

	fileLoader.Load(initFile.c_str());
	cout << "init" << endl;

	terrainFile = fileLoader.Read_Variable_String("terrainFile");

	cout << "terrain" << endl;

	numModels = fileLoader.Read_Variable_Int("numModels");
	for(int index = 0; index < numModels; index++){
		int modelNum = index + 1;

		modelFiles.push_back(fileLoader.Read_Variable_String(fileString.c_str()));
	}

	gameTerrain.loadHeightfield(terrainFile);
	gameTerrain.setScale(10.0f, 0.5f, 10.0f);

	graphicsEng.init(modelFiles);
	graphicsEng.getHeightfieldData(gameTerrain.getTerrainData());
	graphicsEng.setScales(gameTerrain.getYScale(), gameTerrain.getXScale());

	// Temp camera init. Do this from a file later.
	player.setMoveSpeed(10.0);
	player.setRotateSpeed(100.0);
	temp1=0;
	temp2 =0;
}

void MainGame::processInput(){
	events::gameEvent newEvent = graphicsEng.pollEvents();
	float xChange = 0.0f, zChange = 0.0f, pitchChange = 0.0f, yawChange = 0.0f;
	
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
			temp1 += mouseSpeed * float( mousechange1);
			temp2 += mouseSpeed * float(  mousechange2);
		}
		 /*
		 float change1 = (temp1-old1) ;
		 float change2 = (temp2 - old2) ;
		 */
		/*
		if(newEvent.mouseX > gameEvnt.mouseX)
			yawChange = 1.0f;
		else{
			if(newEvent.mouseX < gameEvnt.mouseX)
				yawChange = -1.0f;
			else
				yawChange = 0.0f;
		}
		if(newEvent.mouseY > gameEvnt.mouseY)
			pitchChange = 1.0f;
		else{
			if(newEvent.mouseY < gameEvnt.mouseY)
				pitchChange = -1.0f;
			else
				pitchChange = 0.0f;
		}
		*/
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
					/*
					xChange = -1.0f;
					zChange = -1.0f;
					*/
					break;
				case 'd':
					/*
					xChange = 1.0f;
					zChange = 1.0f;
					*/
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

		player.transformView(xChange, 0.0f, zChange, temp1, temp2, 0.0f);

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
