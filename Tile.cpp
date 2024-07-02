#include "Tile.h"
#include"Resource.h"
Tile::Tile(int tileNum) {
	std::string name = ReadJson::Tiles[tileNum];
	tileType.first = name;
	tileType.second = tileNum;
}
std::pair<std::string, int> Tile::getTile() {
	return tileType;
} 
void Tile::addPeople(int x, int y){
	peoples[pair<int, int>(x, y)] = People();
}
void TileResource::subResourse(int x, int y, int amount)
{
	/*auto it = resources.find(pair<int, int>(x, y));
	if (it!= resources.end())
		resources[pair<int, int>(x, y)] = Resource(resourceType);*/
	this->resources.begin()->second -= amount;
}










TileResource ::TileResource(int tile) :Tile(tile) {
	 resourceType = ReadJson::resourceTypes[tile - 3];
 }
std::string TileResource::getResourceType() {
	return resourceType;
}

void TileResource::addResource( int amount,int x, int y) {
	if (resources.find(pair<int, int>(x, y)) == resources.end())
		resources[std::pair<int, int>(x, y)] = Resource(resourceType, amount);
	else
		resources[std::pair<int, int>(x, y)] += amount;
}



