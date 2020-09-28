#include "userinterface.h"
#include "queue.h"
#include <iostream>

int check = 0;

Userinterface::~Userinterface()
{
	delete _head;
}

Userinterface::Userinterface()
{
	_head = new Queue;
}


void Userinterface::CrateQueue() const
{
	check = _head->CreateQueue();

	if (check)
	{
		std::cout << "\tThe Queue has been created successfelly!\n";
	}

	else
	{
		std::cout << "\tERROR: QUEUE HAS ALREADY CREATED\n";
	}
}

void Userinterface::Push()
{
		std::string name;

		std::cout << "\tPlease, enter what name would you like to put in new case\n\t>> ";
		std::cin >> name;
		std::cout << "\tYour name was added to queue secussfelluy!\n";

		_head->push(name);
}

void Userinterface::Pop() const
{
	if (_head->IsEmpty())
	{
		std::cout << "\tERROR: QUEUE IS EMPTY\n";
	}

	else
	{
		std::cout << "\tThe \"" << _head->pop() << "\" has just lefted from the queue\n";
	}
}

void Userinterface::Front() const
{

	if (_head->IsEmpty())
	{
		std::cout << "\tERROR: QUEUE IS EMPTY\n";
	}

	else
	{
		std::cout << "\tThe first name in queue is \"" << _head->front() << "\"\n";
	}
}

void Userinterface::IsEmpty() const
{
	if (_head->IsEmpty())
	{
		std::cout << "\tThe Queue is empty\n";
	}

	else
	{
		std::cout << "\tThe Queue isn't empty\n";
	}
}

void Userinterface::Help() const
{
	std::cout << "Enter \t/Help or \"0\" for help";
	std::cout << "List of commands:\n\t/CreateQueue\n";
	std::cout << "\t/Push\n\t/Pop\n\t/Front\n\t/IsEmpty\n\t/DeleteQueue\n";
}

void Userinterface::DeleteQueue() const
{
	_head->DeleteQueue();

	check = 0;
}

int CheckAns(std::string ans)
{
	if (ans == "/CreateQueue" || ans == "/Push" || ans == "/Pop" || ans == "/Front" || ans == "/IsEmpty" || ans == "/Help" || ans == "0" || ans == "/DeleteQueue")
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void Userinterface::Init()
{
	std::cout << ">> Enter \"0\" for Help..";

	std::string ans;

	while (true)
	{
		std::cout << ">> ";
		std::cin >> ans;

		if (!CheckAns(ans))
		{
			std::cout << "\tERROR: UNKNOWN COMMAND\n";
		}
		
		else if (ans == "/Help" or ans == "0")
		{
			Help();
		}

		else if (ans == "/CreateQueue")
		{
			CrateQueue();
		}

		else if (check) //Взаимодействие с существующей очередью
		{
			if (ans == "/Push")
			{
				Push();
			}

			else if (ans == "/Pop")
			{
				Pop();
			}

			else if (ans == "/Front")
			{
				Front();
			}

			else if (ans == "/IsEmpty")
			{
				IsEmpty();
			}

			else if (ans == "/DeleteQueue")
			{
				DeleteQueue();
			}
		}

		else
		{
			std::cout << "\tERROR: QUEUE HAS'T CREATED\n";
		}
	}
}