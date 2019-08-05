#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;

using std::string;
using std::vector;
using std::stringstream;

using std::max;


enum COLOR {WHITE, GRAY, BLACK};

void show_edge(const vector<vector<int> >& edge);
void SCC(const vector<vector<int> > &edge, const vector<vector<int> > &edge_t, vector<COLOR> &color, vector<int> &scc);
void one_DFS(const vector<vector<int> >& edge, vector<COLOR>& color, int v, vector<int> &stack);
void re_DFS(const vector<vector<int> >& edge_t, vector<COLOR>& color, int v, vector<int>& stack, int& sign, vector<int>& scc);
void show_scc(const vector<int>& scc);
void MAX(const vector<vector<int> >& edge, vector<COLOR>& color, const vector<int>& scc, const int &scc_num);
void count_DFS(const vector<vector<int> >& edge, vector<COLOR>& color, int v, int &count);

/*
1 2 3



1 2 3
 */

int main()
{
	vector<vector<int> > edge;
	// vector<vector<int> > edge_t;
	

	string input;

	while (getline(cin, input))
	{
		vector<int> this_line;
		int point;
		stringstream input_stream(input);
		while (input_stream >> point)
		{
			this_line.push_back(point);
		}
		edge.push_back(this_line); // ��ȻҪ�����vectorѹ��
	}

	// show_edge(edge);
	// ������Ҫ����ת�þ���
	vector<vector<int> > edge_t(edge.size(), *(new vector<int>));
	for (int i(0); i < edge.size(); ++i)
	{
		for (int j(0); j < edge[i].size(); ++j)
		{
			edge_t[edge[i][j]].push_back(i);
		}
	}
	
	// show_edge(edge); show_edge(edge_t);
	// ������֤�������Լ������ת�ö��ǻ�ȡ��ȷ��

	vector<COLOR> color(edge.size(), WHITE);
	vector<int> scc(edge.size(), -1); // ȫ�����Ϊ-1


	SCC(edge, edge_t, color, scc);
	// show_scc(scc);
	// ��ʱscc��ͬһ����ͨ��֧��sign����ֵ��һ����

	int scc_num(0);
	for (int i(0); i < scc.size(); ++i)
	{
		scc_num = max(scc_num, scc[i]);
	}
	// ���õ�ǿ��ͨƬ�ĸ���

	cout << "I have read the rules about plagiarism punishment" << endl;
	MAX(edge, color, scc, scc_num);

	

	return 0;
}

void show_edge(const vector<vector<int>>& edge)
{
	for (int i(0); i < edge.size(); ++i)
	{
		for (int j(0); j < edge[i].size(); ++j)
		{
			cout << edge[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

void SCC(const vector<vector<int>>& edge, const vector<vector<int>>& edge_t, vector<COLOR>& color, vector<int> &scc)
{
	vector<int> stack; // ��Ϊջʹ��

	for (int i(0); i < edge.size(); ++i)
	// for (int i(edge.size() - 1); i >= 0; --i)
	{
		if (color[i] == WHITE)
			one_DFS(edge, color, i, stack);
	}
	// ���Ͻ����˵�һ�α���������ҷ�����stackջ�н�����һ�����ȵ�׼��

	for (int i(0); i < color.size(); ++i)
		color[i] = WHITE;
	// ���³�ʼ�����е�color

	int sign(0);

	while(!stack.empty()) // ���ջ����
	{
		if (scc[stack.back()] == -1) // ��ʱ�����û�б����
		{
			++sign;
			re_DFS(edge_t, color, stack.back(), stack, sign, scc);
			stack.pop_back();
		}
		else
		{
			stack.pop_back();
		}
	}



	return;
}

void one_DFS(const vector<vector<int>>& edge, vector<COLOR>& color, int v, vector<int> &stack)
{
	color[v] = GRAY;

	for (int i(0); i < edge[v].size(); ++i) // ����v���е��ھ�
	{
		int w = edge[v][i];

		if (color[w] == WHITE)
		{
			one_DFS(edge, color, w, stack);
			// stack.push_back(w);
		}
		else {}
	}

	color[v] = BLACK;
	stack.push_back(v);

	return;
}

void re_DFS(const vector<vector<int>>& edge_t, vector<COLOR>& color, int v, vector<int>& stack, int& sign, vector<int>& scc)
{
	color[v] = GRAY;

	for (int i(0); i < edge_t[v].size(); ++i) // ����v���е��ھ�
	{
		int w = edge_t[v][i];

		if (color[w] == WHITE)
		{
			re_DFS(edge_t, color, w, stack, sign, scc);
			// stack.push_back(w);
		}
		else {}
	}

	scc[v] = sign;
	color[v] = BLACK;


	return;
}

void show_scc(const vector<int>& scc)
{
	for (int i(0); i < scc.size(); ++i)
		cout << scc[i] << " ";
	cout << endl;

	return;
}

void MAX(const vector<vector<int>>& edge, vector<COLOR>& color, const vector<int>& scc, const int &scc_num)
{
	int scc_i(1);
	int max_reach(0);
	int max_scc(0);
	vector<int> reach;
	vector<int> choose;
	for (int i(0); i < scc.size() && scc_i <= scc_num; ++i)
	{
		if (scc[i] == scc_i)
		{
			int count(0);
			// ��ʱ�Ͷ������ͨ��֧�����ж�
			for (int j(0); j < color.size(); ++j)
				color[j] = WHITE;
			count_DFS(edge, color, i, count);
			if (count > max_reach)
			{
				max_reach = count;
				max_scc = scc_i;
			}
			// cout << "!" << count <<" " << scc_num << endl;

			reach.push_back(count);
			++scc_i;
			i = -1;
		}
		else
			continue;
	}

	cout << max_reach << endl;

	for (int i(0); i < reach.size(); ++i)
	{
		
		if (reach[i] == max_reach)
		{
			// cout << "?" << endl;
			choose.push_back((i + 1));
		}
	}
	for (int i(0); i < scc.size(); ++i)
	{
		for (int j(0); j < choose.size(); ++j)
		{
			if (scc[i] == choose[j])
			{
				cout << i << " ";
				break;
			}
		}
	}

	return;
}

void count_DFS(const vector<vector<int>>& edge, vector<COLOR>& color, int v, int &count)
{
	color[v] = GRAY;
	// int count = 0;

	for (int i(0); i < edge[v].size(); ++i) // ����v���е��ھ�
	{
		int w = edge[v][i];

		if (color[w] == WHITE)
		{
			++count;
			// one_DFS(edge, color, w, stack);
			count_DFS(edge, color, w, count);
			// stack.push_back(w);
		}
		else {}
	}

	color[v] = BLACK;

	return;
}
