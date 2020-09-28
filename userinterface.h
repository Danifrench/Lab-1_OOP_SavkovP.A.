#pragma once
#include "queue.h"

class Userinterface
{
public:
	Userinterface();
	~Userinterface();

	void Init();
private:
	void Help() const;
	void CrateQueue() const;
	void Push();
	void Pop() const;
	void Front() const;
	void IsEmpty() const;
	void DeleteQueue() const;

	std::string _answer;
	Queue* _head;
};