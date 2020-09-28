#pragma once
#include <iostream>
#include "member.h"

class Queue
{
public:
	Queue() : _head(nullptr), _tail(nullptr) {}
	
	void push(const std::string& name);
	std::string pop();
	int IsEmpty() const;
	std::string front() const;
	int CreateQueue();
	void DeleteQueue();

private:
	student* _head;
	student* _tail;
};