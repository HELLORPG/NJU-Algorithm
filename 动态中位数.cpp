#include <iostream>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

using std::cin;
using std::cout;
using std::endl;

using std::make_heap;
using std::push_heap;
using std::pop_heap;
using std::sort_heap;
using std::less;
using std::greater;

using std::vector;

// #define GRPDEBUG


int main()
{
	// ����˵�Ƽ�ʹ��scanf��printf���Խ�Լʱ��
	int input(0), n(0);
	vector<int> maxHeap, minHeap;

	make_heap(maxHeap.begin(), maxHeap.end(), less<int>());
	make_heap(minHeap.begin(), minHeap.end(), greater<int>());



	while (scanf("%d", &input) == 1)
	{
		++n; // ������ǰ�����ݴ�С

#ifdef GRPDEBUG
		cout << "input" << input << endl;
#endif
		if (n == 1) // ���ڵ�һ��������Ĭ�Ϸ���min��
		{
			minHeap.push_back(input);
			push_heap(minHeap.begin(), minHeap.end(), greater<int>());
		}

#ifdef GRPDEBUG
		for (const auto &x : maxHeap)
			cout << x << " ";
		cout << endl;
#endif
		else
		{
			if (input > minHeap[0]) // ��ʱӦ�÷�����С��
			{
				minHeap.push_back(input);
				push_heap(minHeap.begin(), minHeap.end(), greater<int>());
			}
			else // ��������
			{
				maxHeap.push_back(input);
				push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
			}

			// ����������֮��ĵ���

			if (maxHeap.size() > n / 2)
			{
				pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
				input = maxHeap.back();
				maxHeap.pop_back();
				minHeap.push_back(input);
				push_heap(minHeap.begin(), minHeap.end(), greater<int>());
			}

			else if (maxHeap.size() < n / 2)
			{
				pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
				input = minHeap.back();
				minHeap.pop_back();
				maxHeap.push_back(input);
				push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
			}
		}

		if (n % 2 == 1)
			printf("%d ", minHeap[0]);
		else
			printf("%d ", maxHeap[0]);
	}
	return 0;
}