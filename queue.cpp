#include  <iostream>
#include "queue.h"

void Queue::push(const std::string& name) //тут много копирования кода
{
	student* newName;
	newName = new student;
	newName->name = name;

	if (_head->next == _tail)
	{
		newName->next = _tail;
		newName->prev = _head;

		_head->next = newName;
		_tail->prev = newName;
	}

	else
	{
		newName->prev = _head;
		newName->next = _head->next;
		newName->next->prev = newName;
		_head->next = newName;
	}
}

std::string Queue::pop()
{
	std::string bufferName;
	student* bufferElement;

	if (_head->next->next == _tail)
	{
		bufferName = _head->next->name;
		bufferElement = _head->next;

		_head->next = _tail;
		_head->prev = _tail;
		_tail->prev = _head;
		_tail->next = _head;

		delete bufferElement;
	}

	else
	{
		bufferElement = _tail->prev;
		bufferName = _tail->prev->name;

		_tail->prev = _tail->prev->prev;
		_tail->prev->next = _tail;

		delete bufferElement;
	}

	return bufferName;
}

int Queue::IsEmpty() const
{
	if (_head->next == _tail)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

std::string Queue::front() const
{
	return _tail->prev->name;
}

int Queue::CreateQueue()
{
	if (_head == nullptr)
	{
		_head = new student;
		_tail = new student;

		_head->prev = _tail;
		_head->next = _tail;
		_tail->next = _head;
		_tail->prev = _head;

		return 1;
	}

	else 
	{
		return 0;
	}
}

void Queue::DeleteQueue()
{
	student* BufferElement;

	while (_head->next != _tail)
	{
		BufferElement = _head->next->next;

		delete _head->next;

		_head->next = BufferElement;
	}

	delete _head;
	delete _tail;

	_head = nullptr;
	_tail = nullptr;
}