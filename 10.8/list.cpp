#include<bits\stdc++.h>
#include"list.h"

bool myList::push(const Item item)
{
	if (full())
		return false;
	this->items[top++] = item;
	return true;
}

bool myList::empty() const
{
	return top == 0 ? true : false;
}

bool myList::full() const
{
	return top == this->LIMIT ? true : false;
}


/*
	visit��������У�ʹ�ú���ָ��pf��Ϊ������
	pfָ��ĺ������������ͬ��
*/
void myList::visit(void(*pf)(Item& item))
{
	for (int i = 0; i < top; i++)
		(*pf)(items[i]);			//���ڴ���(items[i])���������pfָ��ĺ�����
}