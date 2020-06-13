#ifndef Person_H_
#define Person_H_
#include<string>

using std::string;

//��Ȼ������Set��Ϊ�ӿڽ�������໥��������
//�����ڲ� GetӦ����Ϊ˽�к��� ��ΪGet_(class name)���ж��壡

class Person 
{
private:
	string FirstName;
	string LastName;
protected:							//������Ա ���������ֱ�ӷ��ʻ����е�protect��Ա
	virtual void Data() const;		//�����ı�����Աֻ���Դ��ݵ���һ���̳У������˼̳г�ͻ
	virtual void Get();
public:
	Person():FirstName("NULL"),LastName("NULL"){}
	Person(const string& _FirstName, const string& _LastName) :FirstName(_FirstName),LastName(_LastName){}
	Person(const Person& p);
	virtual ~Person() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;	//�������  ���麯�� ���Բ�ʵ�� ֻ����
};

class Gunslinger :virtual public Person
{
private:
	int num;
protected:							//������Ա ���������ֱ�ӷ��ʻ����е�protect��Ա
	void Data() const;				//�Ѻ�����Ϊ������Ա
	void Get();
public:
	Gunslinger() :num(0), Person() {};
	Gunslinger(int _num, const string& _FirstName, const string& _LastName) :Person(_FirstName, _LastName),num(_num){}
	Gunslinger(int _num, const Person& p):num(_num),Person(p){}
	double Draw() const;
	void Show() const;
	void Set();						//��Set�����ӿ� ֱ�ӵ��ó�Ա�ڲ���Get
};

class PokerPlayer :virtual public Person
{
protected:
	void Data() const;
public:
	PokerPlayer():Person(){}
	PokerPlayer(const string& _FirstName,const string& _LastName):Person(_FirstName,_LastName){}
	PokerPlayer(const Person& p):Person(p){}
	int Draw() const;
	void Show() const;
	void Set();
};

class BadDude :public PokerPlayer, public Gunslinger
{
protected:
	void Data() const;
	void Get();
public:
	BadDude(){}
	BadDude(int n, const string& _First, const string& _Last) :Person(_First, _Last), Gunslinger(n, _First, _Last), PokerPlayer(_First, _Last){}
	BadDude(int n,const Person& p):Person(p),Gunslinger(n,p),PokerPlayer(p){}
	BadDude(const Gunslinger& g):Person(g),Gunslinger(g),PokerPlayer(g){}
	BadDude(int n,const PokerPlayer& Pp):Person(Pp),Gunslinger(n,Pp),PokerPlayer(Pp){}
	double Gdraw() const;
	int Cdraw() const;
	void Set();
	void Show() const;
};


#endif // !Person_H_