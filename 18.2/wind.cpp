#include<bits\stdc++.h>
using namespace std;
#include"Cpmv.h"






int main()
{
	//�ֶ�����֮�� ���������ڶ��� ����������������ͷ�һ��
	Cpmv a1;
	a1.Display();

	Cpmv a2("Nanase", "Asuka");
	a2.Display();

	Cpmv a3(a2);
	a3.Display();

	Cpmv a4(a2 + a3);
	a4.Display();

	Cpmv a5 = a2;
	a5.Display();

	Cpmv a6 = a2 + a3;
	a6.Display();



	system("pause");
	return 0;
}