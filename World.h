#pragma once
#include<vector>
#include<string>
#include "Tile.h"
class World
{
	std::vector<std::vector<Tile*>> grid;
public:
	World() {};
	World(std::vector< std::vector<std::string>>&);
	~World();
	void fillGrid(std::vector< std::vector<std::string>>&);
	std::vector<std::vector<Tile*>>& getGrid() { return grid; };
	Tile* selectTile(int x, int y);
	bool insertResource(int count,string resource,int x,int y);
	std::vector<int> selectedResource();
	bool insertPeople(int amount, int x, int y);
};

