#pragma once
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <vector>
#include<string>
using namespace std;
using json = nlohmann::json;
class ReadJson
{
private:
    ReadJson();
public:
    static json config;
    static void init();
    static unordered_map<int, string> Tiles;
    static unordered_map<int, string>& getTiles();
    static vector<int> SizeOfTiles;
    static const vector<int>& getSizeOfTiles();
    static vector<std::string> resourceTypes;
    static vector<std::string>& getResourceTypes();
};