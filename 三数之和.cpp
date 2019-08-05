#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;


int main()
{
	int n(0), target(0);
	vector<int> data;
	int input(0);
	int count(0);
	cin >> n >> target;

	for (int i(0); i < n; ++i)
	{
		cin >> input;
		data.push_back(input);
	}

	sort(data.begin(), data.end());

	for (int i(0); i < data.size(); ++i)
	{
		int left(i + 1), right(data.size() - 1); // ��Ϊ����ָ�룬ͷβ
		int we_need(target - data[i]); // ��Ϊleft��right������Ҫ������������Ӧ��Ԫ�ؼ�������ֵ����we_need
		
		// cout << data[i] << " : " <<we_need << endl;
		while (left < right) // ֻҪ����ָ���λ���������ģ��Ϳ��Լ����������ѭ��
		{
			int now_sum(data[left] + data[right]);
			// cout << data[left] << " " << data[right] << endl;
			if (now_sum < we_need)
				++left; // ��Ϊ��Ҫ���������
			else if (now_sum > we_need)
				--right;
			else
			{
				++count;
				++left;
				--right;
			}
		}
		// cout << "?" << endl;
	}

	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	cout << count;

	return 0;
}