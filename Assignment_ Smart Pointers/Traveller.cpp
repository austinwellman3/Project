#include "Traveller.h"

Traveller::Traveller(std::string name)
{
	this->name = name;
}

Traveller::~Traveller()
{
	std::cout << name+" died!"<<std::endl;
}

std::string Traveller::getName()
{
	return name;
}