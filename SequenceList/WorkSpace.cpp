#include <iostream>
#include "SeqList.hpp"

int main()
{
	SeqList<int> s;
	s.InitList(10);
	s.Push(1);
	s.PrintList();
	return 0;
}
