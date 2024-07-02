#pragma once

#include "Input.h"
#include "World.h"
#include "Tile.h"
#include "People.h"
class Game
{
private:
	Input input;
	World world;
	std::pair<int, int> currentTile;
public:
	Game() :input(), world() {
		input.parse_and_store();
		initworld();
		start();
		inputSteps();
		asserts();
	}
	void initworld() {
		world.fillGrid(input.world->data);
	}
	void start() {
		for (auto& a : input.start)
		{
			if (a.get()->name == Command::RESOURCE)
				resource(a.get());
			else if (a.get()->name == Command::PEOPLE)
				people(a.get());
			else if (a.get()->name == Command::BUILD)
				build(a.get());
		}
	}
	void inputSteps() {
		for (auto a : input.steps)
		{
			if (a.get()->name == Command::SELECT)
				select(a.get());
			else if (a.get()->name == Command::RAIN)
				rain(a.get());
			else if (a.get()->name == Command::WAIT)
				wait(a.get());
			else if (a.get()->name == Command::WORK)
				work(a.get());
		}
	}
	void asserts() {
		for (auto a : input.asserts){
			if (a == "SelectedResource")
				selectedResource();
			else if (a == "SelectedCategory")
				selectedCategory();
		}
	}
	void resource(Command* command) {
		bool a = world.insertResource(std::stoi(command->arguments[0]), command->arguments[1], std::stoi(command->arguments[2]), std::stoi(command->arguments[3]));
	}
	void people(Command* comand) {
		world.insertPeople(std::stoi(comand->arguments[0]), std::stoi(comand->arguments[1]), std::stoi(comand->arguments[2]));
	}
	void build(Command* comand) {
	}
	void select(Command* comand) {
		currentTile = std::pair<int, int>(std::stoi(comand->arguments[0]), std::stoi(comand->arguments[1]));
		/*Tile* t = world.selectTile(currentTail.first, currentTail.second);
		if (typeid(*t) == typeid(TileResource))
		{
		}*/
	}
	void wait(Command* comand) {
		for (size_t i = 0; i < 500; i++);
	}
	void work(Command* comand) {
		/*world.selectTile(currentTail.first, currentTail.second)->getPeople().erase(pair<int, int>(currentTail));
		world.selectTile(std::stoi(comand->arguments[0]), std::stoi(comand->arguments[1]))->addPeople(std::stoi(comand->arguments[0]), std::stoi(comand->arguments[1]));*/
		Tile* currentTile1 = world.selectTile(currentTile.first, currentTile.second);
		if (currentTile1) {
			std::unordered_map<std::pair<int, int>, People> people = currentTile1->getPeople();
			auto it = people.find(std::pair<int, int>(currentTile.first - 1, currentTile.second - 1));
			if (it != people.end()) {
				people.erase(it);
			}
		}
		else {
			return;
		}
		int newX = std::stoi(comand->arguments[0]);
		int newY = std::stoi(comand->arguments[1]);
		Tile* newTile = world.selectTile(newX, newY);
		if (newTile) {
			newTile->addPeople(newX - 1, newY - 1);
			TileResource* tileResource = dynamic_cast<TileResource*>(newTile);
			if (tileResource)
				tileResource->subResourse(newX - 1, newY - 1, 1);
		}
		else {
		}
	}
	void rain(Command* comand) {
		if (std::stoi(comand->arguments[0]) > 2000)
			Resource r("Wood", 1);
		else
			Resource r("Wool", 1);
	}
	void selectedResource() {
		std::cout << "SelectedResource ";
		for (int a : world.selectedResource())
			std::cout << a << " ";
	}
	void selectedCategory() {
		string resource = world.selectTile(currentTile.first, currentTile.second)->getTile().first;
		std::cout << "SelectedCategory " << resource;
	}
};


