#pragma once
#include<iostream>
#include <string>
class Traveller
{
	std::string name;
	public:
		Traveller(std::string name);
		std::string getName();
		~Traveller();
};

