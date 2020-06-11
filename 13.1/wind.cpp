#include<bits\stdc++.h>
using namespace std;
#include"classic.h"
void Bravo(const Cd& cd);

int main()
{
	Cd c1("Beatles", "Capito", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;		//��c1�ĵ�ַ����pcd
	cout << "Using object directly: \n";
	c1.Report();
	c2.Report();
	cout << "Using type cd* pointer to objects: \n";
	pcd->Report();		//pcd�ǵ�ַ��������->,Report���麯�������ݶ��������
	pcd = &c2;
	pcd->Report();		//���ݶ���ѡ��Classic���report
	cout << "Calling a function with a Cd reference argumenet: \n";
	Bravo(c1);


	system("pause");
	return 0;
}

void Bravo(const Cd& cd)
{
	cd.Report();
}

