#ifndef wine_H_
#define wine_H_
#include<string>
#include<valarray>
#include<iostream>
#include<utility>

//NOTICE:ע��using std ��Ҫ���࣡��������
using std::string;
using std::ostream;
using std::pair;
using std::valarray;


class wine {
private:
	string label;
	int years;
	pair<valarray<int>, valarray<int>> v;
public:
	wine(const char* l, int y, const int yr[], const int bot[]);
	wine(const char* l, int y);
	wine(const wine& w);
	wine& operator=(const wine& w);
	virtual ~wine();
	string& Label();	//���� ����ĩ�˲�����const ��ȻӦ����const string&
	int sum() const;
	void getBottles();
	void show() const;
};

#endif // !wine_H_

