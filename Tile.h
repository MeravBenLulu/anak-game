#pragma once
#include <iostream>
#include "ReadJson.h"
#include "Resource.h"
#include "People.h"

namespace std {
	template <>
	struct hash<pair<int, int>> {
		size_t operator()(const pair<int, int>& p) const {
			auto hash1 = hash<int>{}(p.first);
			auto hash2 = hash<int>{}(p.second);
			return hash1 ^ (hash2 << 1);
		}
	};
}
class Tile
{
protected:
	std::pair<std::string, int>tileType;
	const int weight = ReadJson::SizeOfTiles[1];//x
	const int height = ReadJson::SizeOfTiles[0];//y
	std::unordered_map < std::pair <int, int>, People > peoples;
public:
	Tile(int tileNum);
	virtual ~Tile() {};
	std::pair<std::string, int> getTile();
	void addPeople(int x, int y);
	std::unordered_map < std::pair<int, int>, People>& getPeople() { return peoples; };
};
class TileResource :public Tile {
	std::string resourceType;
	std::unordered_map < std::pair <int, int>, Resource > resources;
public:
	TileResource(int tileNum);
	string getResourceType();
	void addResource(int count, int x, int y);
	void subResourse(int x, int y, int amount);
};

