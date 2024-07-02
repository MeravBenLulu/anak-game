//#include "ReadJson.h"
//#include "Input.h"
//#include "World.h"
//using namespace std;
//int main()
//{
//	ReadJson::init();
//	Input myInput;
//	unordered_map<int, string> tails = ReadJson::Tiles;
//	myInput.parse_and_store();
//	World myWorld(myInput.world->data);
//	string name = myInput.start[0]->name;
//	//if (name == Command::RESOURCE) {
//	int amount = stoi(myInput.start[0]->arguments[0]);
//	string resourceName = myInput.start[0]->arguments[1];
//	int x = stoi(myInput.start[0]->arguments[2]);
//	int y = stoi(myInput.start[0]->arguments[3]);
//	myWorld.insertResource(amount, resourceName, x, y);
//	std::cout << "SelectedResource ";
//	for (int a : myWorld.selectedResource()){
//		std::cout << a << " ";
//	}
//	/*int select1 = stoi(myInput.steps[0]->arguments[0]);
//	int select2 = stoi(myInput.steps[0]->arguments[1]);
//	string resource = myWorld.selectTile(select1, select2)->getTile().first;
//	cout << "SelectedCategory " << resource;*/
//
//}
#include "Game.h"
int main() {
	ReadJson::init();
	Game myGame;
}
