#ifndef STACK_H_
#define STACK_H_
#include<iostream>
typedef unsigned long Item;
using std::ostream;
using std::cout;

class Stack {
private:
	enum { MAX = 10 };
	Item* pitems;     //��̬���������������ջ
	int size;
	int top;
public:
	Stack(int n = MAX);
	Stack(const Stack& s);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack& operator=(const Stack& s);
	friend ostream& operator<<(ostream& os, const Stack& s);
};

#endif // !STACK_H_

