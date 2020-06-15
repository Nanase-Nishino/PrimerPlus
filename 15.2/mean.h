#ifndef mean_H_
#define mean_H_
#include<stdexcept>
#include<string>
using std::logic_error;
using std::string;

//mesg���Լ������
//what�������� �ù��캯�����е�sȥ����logic_error!

class bad_hmean :public logic_error
{
private:
	string name;
public:
	explicit bad_hmean(const string& n="hmean", const string& s = "Error in hmean()\n");
	string mesg();
	virtual ~bad_hmean(){}  //�����������Ƽ��׳��쳣 Ӧ�ð��쳣��װ������������
};

bad_hmean::bad_hmean(const string& n,const string& s):name(n),logic_error(s){}

inline string bad_hmean::mesg()
{
	return "hmean() arguments a=-b should be div a+b=0!\n";
}



class bad_gmean :public logic_error
{
private:
	string name;
public:
	explicit bad_gmean(const string& n = "gmean", const string& s = "Error in gmean()\n");
	string mesg();
	virtual ~bad_gmean(){}
};

bad_gmean::bad_gmean(const string& n,const string& s):name(n),logic_error(s){}

inline string bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}

#endif // !mean_H_

