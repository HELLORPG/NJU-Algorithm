#include <iostream>
#include <vector>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;

using std::vector;

using std::max;

int tree_height(vector<int> &preorder, vector<int> &inorder, int in_begin, int in_end, int pre_root, int &d); // rootΪǰ���еĸ��ı�ʾλ��


// int tree_d();
// ��������������ķ�ʽ����ɵĻ��������ظ��ļ��㣬��Ϊֱ����ʵ��߶��кܴ�Ĺ�ϵ
// ����ѧ��ϵ������������ֱ��Ӧ��Ϊ���������ĸ߶�+2����Ϊ��Ҫ������ڵ���������������������ԶҶ�ڵ㣩

int main()
{
	int n(0);
	vector<int> preorder, inorder;
	int input(0);
	int height(0), d(0);

	// ������÷����㷨��Ӧ���Ƿֽ�Ϊ�����������еݹ����

	cin >> n; // ����������

	for (int i(0); i < n; ++i)
	{
		cin >> input;
		preorder.push_back(input);
	}
	for (int i(0); i < n; ++i)
	{
		cin >> input;
		inorder.push_back(input);
	}

	height = tree_height(preorder, inorder, 0, n - 1, 0, d);

	cout << "I have read the rules about plagiarism punishment" << endl;
	cout << height << endl;
	cout << d ;// << endl;
	return 0;
}


int tree_height(vector<int>& preorder, vector<int> &inorder, int in_begin, int in_end, int pre_root, int &d)
{
	// ������Ҫȷ���Ƿ���base-case
	if (in_begin == in_end) // ��ʱ������ֻ�и��ڵ㣬��������Ҷ�ڵ�
	{
		d = 0; // ��ʱֱ��Ӧ����0
		return 0; // ��ʱ�ĸ߶�Ҳ��0
	}

	else if (in_begin > in_end) // ��������ĵ������������Ƚ���ѧ���п�����ĳһ���ڵ��һ��������Ϊ�յģ����Ǿ�������֮���Ȼ��õ�һ���������������ǡ������������޵ģ����޵����־����ڣ����ҵı߽��ǲ�����ģ����Դ˴����յõ��ĸ߶�Ӧ����0��Ϊ�˱���һ�£�������-1������+1֮��õ�0
	{
		d = 0;
		return -1;
	}

	int root_in_inorder(0);
	// ����ǰ��������ԣ������ĸ�Ӧ���Ǵ���������ͷ��
	int ld(d), rd(d);
	int left_height(0), right_height(0);

	// P.S. ������Ϊ����Ҫroot���������Ƹ���λ�ã�������ʵǰ�����������ȡ�Ĳ����ǲ�һ���ģ�������Ҫ�����������������ȡ�Ĳ��֣����У�ǰ�������ֻ��Ҫ��ע���ڵ��λ�þͺ���

	for (int i(in_begin); i <= in_end; ++i)
	{
		if (inorder[i] == preorder[pre_root]) // ������������ҵ�ǰ��������ڵ���ָ���Ԫ�أ���Ϊ�ָ�ָ��Ϊ��������
		{
			root_in_inorder = i; // �����������У���εķָ���ֳ��ˣ�[in_begin , root_in_inorder - 1]������ �� [root_in_inorder + 1 , in_end]������ ��������
			break; // break
		}
	}

	// ������Ҫ����һ������ķ�������Ҫ�ҵ���Ӧ��ǰ�����еı�־�㡪��pre_root����ֵ

	/*
	 * ���ǵõ���������Ϣ���£�
	 * ��������У� [in_begin , root_in_inorder - 1]������ �� [root_in_inorder + 1 , in_end]������
	 * ǰ������У� ���������ĸ��ڵ�Ϊ pre_root
	 * ���Կ��Է����õ���
	 * �������ĸ��ڵ�Ӧ��Ϊ pre_root + 1
	 * �������ĸ��ڵ�����ȽϷ�������ҪԽ�����е������������Կ��Լ��㣬�������Ĵ�СΪ��root_in_inorder - 1 - in_begin + 1 = root_in_inorder - in_begin����ҪԽ����������Ϊ pre_root + root_in_inorder - in_begin + 1
	 */

	left_height = tree_height(preorder, inorder, in_begin, root_in_inorder - 1, pre_root + 1, ld);
	right_height = tree_height(preorder, inorder, root_in_inorder + 1, in_end, pre_root + root_in_inorder - in_begin + 1, rd);

	d = max(ld, rd); // ����������ֵ���ҵ�����һ��
	if (left_height + right_height + 2 > d)
		d = left_height + right_height + 2;

	return max(right_height, left_height) + 1;
}
