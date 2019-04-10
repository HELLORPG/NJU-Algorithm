#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <complex>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

using std::string;
using std::vector;

using std::sort;
using std::min;


// #define GRPDEBUG

// ����һЩ�Բ��Ե�����
/*

9
a ew vc tea oe eat zoo el le 

20 
tea for aet slu uls int shi ni ish hsi what for if it fi a his from a you 

*/

struct Word
{
	string original_word;
	string tag;
	int index;
};

ostream &operator<<(ostream &os, const Word &output);

void sort_by_original(vector<Word> &data);

bool compare_word(const Word &x, const Word &y);

void build_tag(vector<Word> &data);

void sort_by_tag(vector<Word> &data);

bool compare_tag(const Word &x, const Word &y);

void find_anagram(const vector<Word> &data, vector<string> &result);

int main()
{
	int n(0);
	vector<Word> data;
	vector<string> result;
	string input;

	cin >> n;
	for (int i(0); i < n; ++i)
	{
		cin >> input;
		Word x{ input, input, -1 };
		// data.push_back({ input, input, -1 });
		data.push_back(x);
	}
	// ��������е�����

#ifdef GRPDEBUG
	cout << "[ALL INPUT SHOW]    ";
	for (const auto &x : data)
		cout << x << " ";
	cout << endl << endl;
#endif

	sort_by_original(data);

#ifdef GRPDEBUG
	cout << "[AFTER SORT BY WORD]    ";
	for (const auto &x : data)
		cout << x << " ";
	cout << endl << endl;
#endif

	build_tag(data);

#ifdef GRPDEBUG
	cout << "[AFTER BUILD TAG]    ";
	for (const auto &x : data)
		cout << x << " ";
	cout << endl << endl;
#endif

	sort_by_tag(data);

#ifdef GRPDEBUG
	cout << "[AFTER SORT BY TAG]    ";
	for (const auto &x : data)
		cout << x << " ";
	cout << endl << endl;
#endif

	find_anagram(data, result);

	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	// �������̵�Ҫ������������Ķ����ڳ�Ϯ��˵����



	const int length(result.size());
	cout << length << endl;
	// �����λ�ʵĶ���

	if (length == 0)
	{
		
	}
	else
	{
		cout << result[0];
		for (int i(1); i < length; ++i)
			cout << endl << result[i];
	}


	return 0;
}

ostream& operator<<(ostream& os, const Word& output)
{
	os << "{" << output.original_word << " " << output.tag << " " << output.index << "}";
	return os;
}


void sort_by_original(vector<Word>& data)
{
	sort(data.begin(), data.end(), compare_word);

	// ��Ҫ����index���������в���
	const int length = data.size();
	for (int i(0); i < length; ++i)
		data[i].index = i;

	return;
}

bool compare_word(const Word& x, const Word& y)
{
	return x.original_word < y.original_word;
}

void build_tag(vector<Word>& data)
{
	//for (auto &x : data)
	//{
	//	sort(x.tag.begin(), x.tag.end());
	//}
	const int length(data.size());
	for (int i(0); i < length; ++i)
		sort(data[i].tag.begin(), data[i].tag.end());
	return;
}

void sort_by_tag(vector<Word>& data)
{
	sort(data.begin(), data.end(), compare_tag);

	return;
}

bool compare_tag(const Word& x, const Word& y)
{
	return x.tag < y.tag;
}

void find_anagram(const vector<Word>& data, vector<string>& result)
{
	const int length(data.size());

	if (length == 1 || length == 0)
		return;
	// ������Ϊ������ֵ�������������ǻ��ǽ���������

	else
	{
		int min_index(INT32_MAX);
		int real_index(-1);
		for (int i(1), j(0); i < length; ++i, ++j)
		{
			if (data[i].tag == data[j].tag)// ��ʱ�ʹ�������λ��
			{
				if (min_index == INT32_MAX)
				{
					min_index = min(data[i].index, data[j].index);
					if (data[i].index > data[j].index)
						real_index = j;
					else
						real_index = i;
				}
				else
				{
					const int old_min = min_index;
					min_index = min(data[i].index, min_index);
					if (data[i].index < old_min)
						real_index = i;
				}
#ifdef GRPDEBUG
				cout << "(" << data[i].tag << ") in " << min_index << endl;
				cout << (i == length - 1) << endl;
#endif
				if (i == length - 1)
					goto special;
			}

			else
			{
				special:
				if (min_index == INT32_MAX)
					continue;
				else
				{
					result.push_back(data[real_index].original_word);
#ifdef GRPDEBUG
					cout << "[" << real_index << "] is " << data[real_index].original_word << endl;
#endif
					min_index = INT32_MAX;
				}
			}
		}
	}

	sort(result.begin(), result.end());

	return;
}
