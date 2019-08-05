#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <string>

#include <climits>

using std::cout;
using std::cin;
using std::endl;

using std::vector;
using std::string;

using std::deque; //˫����л��Ǳ������ˣ���Ϊ���ܶ��м�����ݽ�������

using std::priority_queue;
using std::make_heap;
using std::less;
using std::greater;

using std::sort;
using std::swap;

string find_mid(vector<string> &list, int begin, int end, int size); //ʹ�õ��Ƿǵ�����
//ͨ���ݹ�ķ��������ÿ�����λ���㷨�ҵ���Ӧ����λ��

int main()
{
	int k(0), n(0); //K��2K+1�ı�׼��n�������ĳ���

	string input;

	/*while (cin >> k >> n)
	{*/

	cin >> n >> k;
	vector<string> list;
	for (int i(0); i < n; ++i)
	{
		cin >> input;
		list.push_back(input);
	}


	string midnum = find_mid(list, 0, n - 1, n);

	// cout << midnum << endl;
	/*for (auto c : list)
		cout << c << " ";
	cout << endl;*/
	//cout << midnum << endl;
	//������֤������λ��Ϊ���֣����������ַ�Ϊ����������������λ��С���Ҳ෴֮

	//֮����ҪѰ��K��ǰ�󲿷�
	for (int i(0); i < k; ++i) //��ҪѰ��K��
	{
		string max = "";
		int now_max_place(0);

		for (int j(0); j < (n + 1) / 2 - i - 1; ++j) // �������ֹ�����������޸ģ���AC��
		{
			if (list[j] > max)
			{
				max = list[j];
				now_max_place = j;
			}
		}
		swap(list[now_max_place], list[(n + 1) / 2 - i - 2]);

		/*for (auto c : list)
			cout << c << " ";
		cout << endl;*/
	}

	for (int i(0); i < k; ++i)
	{
		string min = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		int now_min_place(0);

		for (int j(n / 2 + i + 1); j < n; ++j)
		{
			if (list[j] < min)
			{
				min = list[j];
				now_min_place = j;
			}
		}
		swap(list[now_min_place], list[n / 2 + i + 1]);
/*
		for (auto c : list)
			cout << c << " ";
		cout << endl;*/
	}

	/*for (auto c : list)
		cout << c << " ";
	cout << endl;*/

	for (int i(n / 2 - 1 + n % 2 - k); i < n / 2 + k - 1 + n % 2; ++i)
		cout << list[i] << " ";
	cout << list[n / 2 + k - 1 + n % 2];
	/*cout << endl;

	sort(list.begin(), list.end());
	for (auto c : list)
		cout << c << " ";
	cout << endl; */
	return 0;
}

string find_mid(vector<string>& list, int begin, int end, int size)
{
	//���п�����λ����Ѱ��
	if (size == 1)
	{
		//�����ʱֻ��һ�����ȵ���������Ч��
		return list[0];
		//return 0;
	}

	//ʣ�µĲ��ֵĳ�������Ҫ���л�������

	int i(begin); //����begin��keyֵ
	int j(i + 1);
	for (; j <= end; ++j)
	{
		if (list[j] <= list[begin])
		{
			//��ʱ����ָԪ�ر�ͷԪ��ҪС
			++i; //��Ҫ������Ԫ����i����֮���λ�ã����Ԫ���������Ǳ�begin��Ԫ�ش�
			swap(list[i], list[j]);
		}
	}
	swap(list[begin], list[i]);


	//�����Ҫ���ֳ��ݹ�ķ�����

	if (i < size / 2 - 1 + size % 2) //������������
		return find_mid(list, i + 1, end, size);
	else if (i > size / 2 - 1 + size % 2)
		return find_mid(list, begin, i - 1, size);
	else
	{
		if (size % 2 == 1)
			return list[i];
		//return i;
		else
		{
			
			return list[i];
		}
	}
}
