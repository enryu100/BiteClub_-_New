#include "GameFactory.h"


GameObject GameFactory::Create(std::string type){
	GameObject tmp = GameObject(type);
	return tmp;
}