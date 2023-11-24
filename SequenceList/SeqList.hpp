#pragma once
#include <iostream>
#include <string>

template <class T>
class SeqList
{
public:
	SeqList();
	void InitList(int MaxSize);
	bool Push(T val);
	void IncreaseSize(int len);
	void PrintList();

private:
	T* data;
	int MaxSize;
	int length;
};

template<class T>
SeqList<T>::SeqList()
	:data(nullptr), MaxSize(0), length(0)
{
}

template<class T>
void SeqList<T>::InitList(int MaxSize)
{
	data = new T[MaxSize];
	length = 0;
	this->MaxSize = MaxSize;
}

template<class T>
bool SeqList<T>::Push(T val)
{
	if (length >= MaxSize)
		return false;
	data[length++] = val;
	return true;
}

template<class T>
void SeqList<T>::IncreaseSize(int len)
{
	T* temp = data;
	data = new T[MaxSize + len];
	for (int i = 0; i < length; i++)
	{
		data[i] = temp[i];
	}
	MaxSize += len;
}

template<class T>
void SeqList<T>::PrintList()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << data[i] << " ";
	}
}





