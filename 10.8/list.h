#ifndef list_H_
#define list_H_

typedef int Item;

class myList {
private:
	static const int LIMIT = 5;
	Item items[LIMIT];
	int top;
public:
	myList() { top = 0; }
	bool push(const Item);
	bool empty() const;
	bool full() const;
	void visit(void(*pf)(Item& m));//��ʾĳ�������� ����ָ��ָ��ĺ�������ִ�����ֺ���
};

#endif // !list_H_

