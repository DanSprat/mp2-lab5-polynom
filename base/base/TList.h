#pragma once
#include "pch.h"
#include <iostream>
using namespace std;
template <typename T>
//////////////////   ����� ������  /////////////////////////
struct Link
{
	Link * pNext;
	T data;
	Link(T data = T(), Link * pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
	~Link() { delete pNext; }
};
/////////////////////////////////////////////////////////////////////////

template <typename T>

//////////////// ����������� ������ ////////////////////////
class Tlist
{
public:
	Tlist();
	~Tlist();
	bool isEmpty();//������ ������ �� ������
	void push_back(T); // ������� � �����
	void push_first(T); // ������� � ������
	void push_pos(T, int); // ������� �� ������� 
	void delete_elem(int pos); // �������� n-��� ��������
	int len() { return size; } // ������ �����
	Link <T> *  find_elem(T); // ����� ��������
private:
	int size;
	Link <T> * head;
};
//////////////////////////////////////////////////////////////////////////

///////////////////// ������ ///////////////////////////////////
template <typename T>
Tlist <T>::Tlist()
{
	size = 0;
	head = nullptr;
}

template<typename T>
inline Tlist<T>::~Tlist()
{
	while (head->pNext != nullptr)
	{
		Link <T> *deleted = head;
		head = head->pNext;
		delete deleted;
	}
	delete head;
}

template<typename T>
inline bool Tlist<T>::isEmpty()
{
	return size == 0;
}

template<typename T>
void Tlist<T>::push_back(T data) // �������� �� "�����"
{
	if (head == nullptr)
	{
		head = new Link <T>(data);
	}
	else
	{
		Link <T> *tmp = this->head;
		while (tmp->pNext != nullptr)
		{
			tmp = tmp->pNext;
		}
		tmp->pNext = new Link <T>(data);
	}
	size++;
}

template<typename T>
void Tlist<T>::push_first(T data) // �������� � "������"
{
	if (head == nullptr)
	{
		head = new Link <T>(data);
	}
	else
	{
		Link <T> *tmp;
		tmp = new Link <T>(data);
		tmp->pNext = head;
		head = tmp;
	}
	size++;
}

template<typename T>
void Tlist<T>::push_pos(const  T data, const int pos) // �������� �� �������
{
	if (pos > size)
		throw 1;
	if (pos == 0) {
		push_first(data);
		return;
	}
	if (pos == size) {
		push_back(data);
		return;
	}
	int i = 0;
	Link <T>* tmp;
	Link <T> * PreLink = head; // ��������� ���������� ������
	while (i != pos - 1)
	{
		PreLink = PreLink->pNext;
		i++;
	}
	tmp = new Link <T>(data);
	tmp->pNext = PreLink->pNext;
	PreLink->pNext = tmp;
	size++;
}

template<typename T>
void Tlist<T>::delete_elem(int pos)
{
	try {
		if (pos >= size || pos < 0)
			throw 1;
	}
	catch (int i)
	{
		cout << "������ �" << i << ": �������� �������" << endl;
		return;
	}
	Link <T> * tmp = head;
	Link <T> * deleted;
	if (pos == 0)
	{
		if (head->pNext != nullptr)
		{
			tmp = tmp->pNext;
			delete[] head;
			head = tmp;
			size--;
			return;
		}
		tmp = tmp->pNext;
		deleted = head;
		delete[] deleted;
		head = tmp;
		size--;
		return;
	}
	for (int i = 0; i < pos - 1; i++)
	{
		tmp = tmp->pNext;
	}
	deleted = tmp->pNext;
	if (deleted->pNext != nullptr)
	{
		if (deleted != head)
			tmp->pNext = deleted->pNext;
	}
	else
	{
		tmp->pNext = nullptr;
	}
	size--;
	delete[] deleted;
}

template<typename T>
Link <T> * Tlist<T>::find_elem(T data)
{
	Link <T> *back;
	Link <T> *tmp = head;
	if (size == 0)
		return tmp;
	for (int i = 0; i < size; i++)
	{
		if (tmp->data == data)
			return  tmp;
		tmp = tmp->pNext;
	}
	return tmp;
}