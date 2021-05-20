#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct item
{
	string name;
	double priñe;
};


int main()
{
	vector<item>shop ;
	int i;
	string name;
	double priñe;
	cout << "enter count of products\n";
	cin >> i;
		for (int b = 0; b < i; b++)
	{
		cout << "enter name of product\n";
		cin >>name;
		cout << "enter price product\n";
		cin >> priñe;
		shop.push_back({ name,priñe });
	}

		cout << "enter what are u looking for\n";
		cin >> name;

		for (int b = 0; b < i; b++)
		{
			if (name == shop[b].name)
			{
				cout << shop[b].priñe;
			}

		}
	
		return 0;
}