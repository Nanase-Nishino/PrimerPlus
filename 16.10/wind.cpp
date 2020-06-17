#include<bits\stdc++.h>
using namespace std;


struct Review {
	string title;
	int rating;
	double price;
};


bool FillReview(shared_ptr<Review>& rr);
void showReview(shared_ptr<Review>& rr);

int main()
{
	vector<shared_ptr<Review>> books;
	shared_ptr<Review> temp(new Review);
	while (FillReview(temp))
	{
		books.emplace_back(temp);
		temp.reset(new Review);//ָ��Ҫ��� ����newһ���µ�ֵ
	}

	if (books.size())
	{
		cout << "Thank you. You entered the following " << books.size() << " ratings:\n" << "Rating\tBook\tPrices\n";
		for_each(books.begin(), books.end(), showReview);
	}

	cout << "Please Enter the model for appear books: ";
	cout << "You can choose 6 kinds of ranting for books.\n";
	cout << "q to quit!" << endl;
	
	char ch;
	cin >> ch;
	
	while (ch != 'q')
	{
		switch (ch)
		{
		case 'o'://ԭʼ˳��
			for_each(books.begin(), books.end(), showReview);
			break;
		case 'r'://���˳��
		{
			vector<shared_ptr<Review>> tBooks(books);
			random_shuffle(tBooks.begin(), tBooks.end());
			for_each(tBooks.begin(), tBooks.end(), showReview);
			break;
		}
		case 'a'://����ĸ��˳��
		{
			vector<shared_ptr<Review>> tBooks(books);
			sort(tBooks.begin(), tBooks.end(), [](shared_ptr<Review>& r1, shared_ptr<Review>& r2) {
				return r1->title < r2->title;
				});
			for_each(tBooks.begin(), tBooks.end(), showReview);
			break;
		}
		case 'b'://����������
		{
			vector<shared_ptr<Review>> tBooks(books);
			sort(tBooks.begin(), tBooks.end(), [](shared_ptr<Review>& r1, shared_ptr<Review>& r2) {
				return r1->rating < r2->rating;
				});
			for_each(tBooks.begin(), tBooks.end(), showReview);
			break;
		}
		case 'c'://����������
		{
			vector<shared_ptr<Review>> tBooks(books);
			sort(tBooks.begin(), tBooks.end(), [](shared_ptr<Review>& r1, shared_ptr<Review>& r2) {
				return r1->rating > r2->rating;
				});
			for_each(tBooks.begin(), tBooks.end(), showReview);
			break;
		}
		case 'd'://���۸�����
		{
			vector<shared_ptr<Review>> tBooks(books);
			sort(tBooks.begin(), tBooks.end(), [](shared_ptr<Review>& r1, shared_ptr<Review>& r2) {
				return r1->price < r2->price;
				});
			for_each(tBooks.begin(), tBooks.end(), showReview);
			break;
		}
		case 'e'://���۸���
		{
			vector<shared_ptr<Review>> tBooks(books);
			sort(tBooks.begin(), tBooks.end(), [](shared_ptr<Review>& r1, shared_ptr<Review>& r2) {
				return r1->price > r2->price;
				});
			for_each(tBooks.begin(), tBooks.end(), showReview);
			break;
		}
		}
		cout << "Enter again: ";
		cin >> ch;
	}
	
	system("pause");
	return 0;
}

bool FillReview(shared_ptr<Review>& rr)
{
	cout << "Enter book title (quit to quit): ";
	getline(cin, rr->title);
	if (rr->title == "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> rr->rating;
	cout << "Enter book prices: ";
	cin >> rr->price;
	cin.get();
	return true;
}

void showReview(shared_ptr<Review>& rr)
{
	cout << rr->rating << "\t" << rr->title << "\t" << rr->price << endl;
}