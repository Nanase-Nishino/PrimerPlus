#include<bits\stdc++.h>
using namespace std;


//̫���˾Ͳ�д�򲻿����ж���
const char* file1 = "mat.dat";
const char* file2 = "pat.dat";
const char* file3 = "matnpat.dat";
int main()
{
	ofstream fout;
	ifstream fin;
	string s;
	set<string> Mat;
	set<string> Pat;

	//���������ļ�
	fout.open(file1);
	cout << "Enter Mat's friend <q to quit>: " << endl;
	while (getline(cin, s) && s != "q")
		fout << s << endl;
	fout.close();
	fout.open(file2);
	cout << "Enter Pat's friend <q to quit>: " << endl;
	while (getline(cin, s) && s != "q")
		fout << s << endl;
	fout.close();


	//���������ļ�
	fin.open(file1);
	while (!fin.eof())
	{
		getline(fin, s);
		Mat.insert(s);
	}
	cout << "Mat's friend: ";//���û��� ֮ǰд��ʱ���һ�����ִ���һ�����з�
	for (const string& x : Mat)
		cout << x << endl;
	fin.close();
	fin.open(file2);
	while (!fin.eof())
	{
		getline(fin, s);
		Pat.insert(s);
	}
	fin.close();
	cout << "Pat's friend: ";
	for (string x : Pat)
	{
		cout << x << endl;
		Mat.insert(x);
	}

	cout << "Mat and Pat's friend: ";
	for (string x : Mat)
	{
		cout << x << endl;
		fout << x << endl;
	}
	fout.close();




	system("pause");
	return 0;
}