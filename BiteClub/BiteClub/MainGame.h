/**
* MainGame.h
*
* Author: Alfred Malone
* Date: 17/4/2017
*
* The MainGame class runs the whole shebang, with all other engines under its control.
*/
#pragma once

#include "Graphics.h"
#include "Terrain.h"
#include "Camera.h"
#include "lua_Script.h"
#include <iostream>
#include <vector>

/// An enumeration to make the game state transitions easier.
enum class GameState {PLAY, EXIT};

/**
* @class MainGame
* @brief A class that holds all of the game components and runs the game loop.
*
* The MainGame class is responsible for holding the instances of each component of the game,
* using them (and the input it gathers) to create a functioning game world. At least, that
* is the theory.
*
* @author Alfred Malone
* @version 01
* @date 17/4/2017 Alfred Malone, created class
*
* @author Alfred Malone
* @version 02
* @date 26/4/2017 Alfred Malone, added Doxygen comments (and plenty more previously)
*
* @author Alfred Malone
* @version 03
* @date 27/4/2017 Alfred Malone, added file loader for init from files
*
* @author Ben Porter
* @version 04
* @date 27/4/2017 Changed how game recieves input from mouse and how it uses camera functions
* @todo Get collision detection. We're toast.
*
* @bug My shoddy redo of the Camera class.
*/
class MainGame
{
public:
	/**
	* The constructor for a MainGame object.
	* Initialises the game state.
	*/
	MainGame(void);

	/**
	* The destructor for a MainGame object.
	*/
	~MainGame(void);

	/**
	* @brief Initialises and runs the game.
	* @param initFile - The file name of the initialising file
	*
	* run simply initialises and runs the game.
	*/
	void run(std::string initFile);

private:
	float old1;
	float old2;
	float temp1;
	float temp2;
	float mouseSpeed;
	/// The graphics engine.
	graphics::GraphicsEngine graphicsEng;
	/// The game terrain or map.
	terrain::Terrain gameTerrain;
	/// The previous event that occurred in the game. Constantly updated.
	events::gameEvent gameEvnt;
	/// The first-person camera. Currently the only way to provide the game with a player.
	Camera player;
	/// The current state the game is in, be it STOP or PLAY.
	GameState currentState;
	/// The loader and reader of the initialising file.
	lua_Script fileLoader;

	/**
	* @brief Initialises each component of the game engine.
	* @param initFile - The file name of the initialising file
	*
	* initSystems sets each component of the game engine (graphics engine, terrain, camera)
	* to an initial state. These states are provided by a values from a file.
	*/
	void initSystems(std::string initFile);
	/**
	* @brief Processes any user input and passes it to the game components.
	*
	* processInput uses the graphics engine's event handling to determine if the user has
	* input anything, then updates the graphics engine and camera (and perhaps the game
	* state) with said input. Using the graphics engine for event handling is an unwanted
	* occurrence, but will have to do for now.
	*/
	void processInput();
	/**
	* @brief Provides the main control loop for the game.
	*
	* gameLoop contains the game's control loop, which, once started, processes input and
	* displays the world until the game is quit.
	*/
	void gameLoop();
};

