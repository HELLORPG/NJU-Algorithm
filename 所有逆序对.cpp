#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;


// #define DEBUG_SHOW


// ���ȵ��������ʹ��long long����Ϊ���ݿ��ܻ�ܴ�

long long ReversePair(vector<string> &list, int left, int right);

long long Merge(vector<string> &list, int left, int mid, int right);
// ��Ҫ����Խ���ߵ����������е�����������������
// ͬʱ���¹鲢��Ϊ�������е�����


int main()
{
	/*string a("apple"), b("banana");
	cout << (a < b) << endl;*/
	//����string���Ϳ���ֱ��ʹ�ô���С�ڽ����ֵ����ж�

	/*
	 * ��ȡ�鲢�ķ�ʽ�������
	 * ��һ�����д����м�ֿ�����Ϊ�������������
	 * �����������зֱ��������Եĸ������ٽ����������п����е�������ҳ������кϲ����
	 * ֮���������кϲ����򣬵õ�һ���������У�������һ�ε����
	 */

	

	int n(0);
	string input;
	vector<string> data;

	cin >> n;
	// �������
	for (int i(0); i < n; ++i)
	{
		cin >> input;
		data.push_back(input);
	}
	// ���������
	
#ifdef DEBUG_SHOW
	cout << "-----> INPUT ALL SHOW:" << endl;
	for (auto word : data)
		cout << word << " ";
	cout << endl;
#endif

	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	// �����ʦҪ��������ַ��������Ķ����ڳ�Ϯ��˵��

	cout << ReversePair(data, 0, n - 1) << endl;
	return 0;
}

long long ReversePair(vector<string>& list, int left, int right)
{
	if (left == right)
		return 0; // base-case

	// recursion-case
	long long mid = (left + right) / 2;

	long long left_recursion = ReversePair(list, left, mid);
	long long right_recursion = ReversePair(list, mid + 1, right);
	long long merge_result = Merge(list, left, mid, right);

	return left_recursion + merge_result + right_recursion;
}

long long Merge(vector<string>& list, int left, int mid, int right)
{
	// ���ڽ��������֣��ϲ���������������
	long long reverse_pair_count(0); // ���ڼ���
	long long i(left), j(mid + 1); // ��Ϊ����������ָ��

	for (; i <= mid && j <= right; )
	{
		if (list[i] > list[j])
		{
			reverse_pair_count += mid - i + 1;
			// ÿ������Ԫ�أ�������������ӣ�m-i+1��Ϊ��Ԫ�ص�������β��Ԫ������
			++j;
		}

		else
		{
			++i;
		}
	}

	sort(&list[left], &list[right] + 1);

	return reverse_pair_count;
}
