#pragma once
#include <iostream>

struct student 
{
	std::string name;
	student* next;
	student* prev;
};