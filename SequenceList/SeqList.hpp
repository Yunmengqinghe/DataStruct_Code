#pragma once
#include <iostream>
#include <string>

template <class T>
class SeqList
{
public:
	SeqList();
	void ListInit(int MaxSize);
	bool Push(T val);
	void IncreaseSize(int len);
	void ListPrint();
	bool ListInsert(int index, T val);
	bool ListDelete(int index, T& val);
	T GetElem(int index); //通过下标寻值
	int LocateElem(T val); //返回对应数值下标

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
void SeqList<T>::ListInit(int MaxSize)
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
void SeqList<T>::ListPrint()
{
	for (int i = 0; i < length; i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

template<class T>
bool SeqList<T>::ListInsert(int index, T val)
{
	if (index < 0 || index > MaxSize || length >= MaxSize)
		return false;

	for (int i = length;i > index;i--)
		data[i] = data[i - 1];
	data[index] = val;

	length++;
	return true;
}

template<class T>
bool SeqList<T>::ListDelete(int index, T& val)
{
	if (index < 1 || index > length)
		return false;

	val = data[index - 1];
	for (int i = index;i < length;i++)
		data[i - 1] = data[i];

	length--;
	return true;
}

template<class T>
T SeqList<T>::GetElem(int index)
{
	if (index < 0 || index >= length)
		throw std::out_of_range("不合法的范围");

	return data[index];
}

template<class T>
int SeqList<T>::LocateElem(T val)
{
	for (int i = 0;i < length;i++)
		if (data[i] == val)
			return i;
	return -1;
}





