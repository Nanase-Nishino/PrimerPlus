#include<bits\stdc++.h>
using namespace std;
#include"Nana.h"



// ֻҪ��һ�����벻��getline,��������cin.get()���˿ո�
// cin��������/�ַ�ʱ���Զ��Կո���й���

int main()
{
	ABC* p_base[4];
	for (int i = 0; i < 4; i++)
	{
		char fullname[40];
		int level;
		int rating;
		int kind;
		cout << "Enter fullname: ";
		cin.getline(fullname, 40);
		cout << "Enter level: ";
		cin >> level; 
		cin.get();
		cout << "1 for base,2 for lack,3 for has: ";
		while (cin >> kind && (kind != 1 && kind != 2 && kind != 3))
			cout << "Please 1,2,or 3: ";
		cin.get();		//��������ʱ ���з��������뻺����
		if (kind == 1)
		{
			char label[40];
			int rating;
			cout << "Enter the label: ";
			cin.getline(label, 40);
			cout << "Enter the rating: ";
			cin >> rating;
			cin.get();
			p_base[i] = new baseDMA(label, rating, fullname, level);
		}
		else if (kind == 2)
		{
			char color[40];
			cout << "Enter the color: ";
			cin.getline(color, 40);
			p_base[i] = new lacksDMA(color, fullname, level);
		}
		else if (kind == 3)
		{
			char style[40];
			cout << "Enter the style: ";
			cin.getline(style, 40);
			p_base[i] = new hasDMA(style, fullname, level);
		}
	}

	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		p_base[i]->View();
		cout << endl;
	}


	system("pause");
	return 0;
}



