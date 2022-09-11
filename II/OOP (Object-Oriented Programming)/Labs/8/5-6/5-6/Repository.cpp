#pragma once

#include "Repository.h"
#include "MyException.h"
#include <string>

using namespace std;

Repository::Repository(): BaseRepository{}
{
}


Repository::~Repository()
{
}

void Repository::add(Dog & dog)
{
	vector<Dog>::iterator iterator = find(dog);

	if (iterator != dogs.end()) {
		throw MyException{ std::string {dog.getName()} + " already exists." };
	}

	dogs.push_back(dog);
}

void Repository::update(Dog & dog)
{
	vector<Dog>::iterator iterator = find(dog);

	if (iterator == dogs.end()) {
		throw MyException{ std::string {dog.getName()} + " doesn't exists." };
	}

	*iterator = dog;
}

void Repository::remove(Dog & dog)
{
	vector<Dog>::iterator iterator = find(dog);

	if (iterator == dogs.end()) {
		throw MyException{ std::string {dog.getName()} +" doesn't exists." };
	}

	dogs.erase(iterator);
}

//void Repository::setFilePath(char * filePath)
//{
//	throw MyException{ "Cannot set file path to in-memory repository." };
//}

