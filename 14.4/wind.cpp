#include<bits\stdc++.h>
using namespace std;
#include"Person.h"
#include<windows.h>


int main()
{
	Person* p[5];
	int ct;
	for (ct = 0; ct < 5; ct++)
	{
		char choice;
		cout << "Enter the Person: \n";
		cout << "g: Gunslinger\tp: PokePlayer \n";
		cout << "b: BadDude\tq: quit\n";

		//���������Enter the Person: ����
		HANDLE hStdout;
		COORD cursorPos;
		
		CONSOLE_SCREEN_BUFFER_INFO blnfo;
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdout, &blnfo);			//��ȡ��ǰ���λ��
		cursorPos.X = strlen("Enter the Person: ");			//��ȡ��һ�е����ݳ���,��ΪX����
		cursorPos.Y = blnfo.dwCursorPosition.Y - 3;			//���ú��������Y����
		SetConsoleCursorPosition(hStdout, cursorPos);		//��궨λ


		cin >> choice;

		//���ص�ԭ��
		cursorPos = blnfo.dwCursorPosition;					
		SetConsoleCursorPosition(hStdout, cursorPos);


		while (!strchr("gpbq", choice))
		{
			cout << "Please Enter as p/g/b/q: ";
			cin >> choice;
		}

		if (choice == 'q')
			break;

		switch (choice)
		{
		case'p':
			p[ct] = new PokerPlayer;
			break;
		case'b':
			p[ct] = new BadDude;
			break;
		case'g':
			p[ct] = new Gunslinger;
			break;
		}
		cin.get();
		p[ct]->Set();
	}


	//û�����ö�̬���鳤�� ���볤�ȱ���Ϊ5 ��Ȼ�ᷢ������ 
	cout << "\nHere is your men: \n";
	for (int i = 0; i < 5; i++)
	{
		cout << endl;
		p[i]->Show();
	}
	for (int i = 0; i < 5; i++)
		delete p[i];
	cout << "Bye\n";



	system("pause");
	return 0;
}



