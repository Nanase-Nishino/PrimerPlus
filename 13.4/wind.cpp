#include<bits\stdc++.h>
using namespace std;
#include"Nana.h"

// b.���������������¶���
// c.operator=()�޷��̳� operator<<()����Ԫ

int main()
{
	Port wine1("Gallo", "tawny", 20);
	VintagePort wine2("Nanase", "Nishino", 25, "Nanasemeru", 23);
	VintagePort wine3("Asuka", "Satio", 22, "Dark bird", 23);
	wine1.Show();
	cout << wine1 << endl;
	wine2.Show();
	cout << wine2 << endl;
	wine3.Show();
	cout << wine3 << endl;

	wine1 += 10;
	cout << wine1 << endl;

	wine2 += 10;
	cout << wine2 << endl;

	wine3 -= 50;
	wine3 -= 22;
	cout << wine3 << endl;

	Port wine4(wine3);
	cout << wine4 << endl;

	Port* wine5 = &wine4;
	wine5->Show();

	wine5 = &wine2;
	wine5->Show();



	system("pause");
	return 0;
}



