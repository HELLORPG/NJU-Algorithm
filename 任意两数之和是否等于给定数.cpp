#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;


int main()
{
	int n(0);
	int x(0); //��ΪĿ������

	cin >> n; //���������ݵĸ���
	vector<int> list;

	int input(0);
	for (int i(0); i < n; ++i)
	{
		cin >> input;
		list.push_back(input);
	}
	cin >> x;

	for (int i(0); i < n; ++i)
	{
		for (int j(i + 1); j < n; ++j)
		{
			if (list[i] + list[j] == x)
			{
				cout << list[i] << " " << list[j] << endl;
			}
		}
	}
	return 0;
}