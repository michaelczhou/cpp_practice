#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// ���������ֱ����㷨
class Traverse {
public:
	// 1. ǰ�������root, left, right��
	void PreOrder(TreeNode* root) {
		if (root != NULL) {
			cout << root->val << " ";
			PreOrder(root->left);
			PreOrder(root->right);
		}
	}
	// �ǵݹ�
	void PreOrder2(TreeNode* root) {
		TreeNode* p = root;
		stack<TreeNode*> stk;
		do {
			while (p != NULL) {  // ���������㣬��ջ����ӡ
				stk.push(p);
				cout << p->val << " ";
				p = p->left;
			}
			if (!stk.empty()) {  // ��ջ����ָ���ҽ��
				p = stk.top(); stk.pop();
				p = p->right;
			}
		} while (!stk.empty() || p != NULL);  // ջ���ջ��ߵ�ǰ�ڵ㲻�գ������ѭ��
	}

	// 2. ���������left, root, right��
	void InOrder(TreeNode* root) {
		if (root != NULL) {
			InOrder(root->left);
			cout << root->val << " ";
			InOrder(root->right);
		}
	}
	// �ǵݹ�
	void InOrder2(TreeNode* root) {
		TreeNode* p = root;
		stack<TreeNode*> stk;
		do {
			while (p != NULL) {  // ���������㣬��ջ
				stk.push(p);
				p = p->left;
			}
			if (!stk.empty()) {
				p = stk.top(); stk.pop(); 
				cout << p->val << " ";  // ��ӡ
				p = p->right;
			}
		} while (!stk.empty() || p != NULL);

	}

	// 3. ���������left, right, root��
	void PostOrder(TreeNode* root) {
		if (root != NULL) {
			PostOrder(root->left);
			PostOrder(root->right);
			cout << root->val << " ";
		}
	}
	// �ǵݹ�
	void PostOrder2(TreeNode* root) {
		TreeNode* p = root;
		TreeNode* prev = NULL;  // ��¼�ϴη��ʹ��Ľڵ�
		stack<TreeNode*> stk;
		do {
			while (p != NULL) {
				stk.push(p);
				p = p->left;
			}
			TreeNode* top = stk.top();
			// �������Ϊ�ջ����Ѿ����ʹ�������ʵ�ǰ�ڵ㣬����ջ
			// �������������
			if (top->right == NULL || top->right == prev) {
				cout << top->val << " ";
				prev = top;
				stk.pop();
			}
			else p = top->right;
		} while (!stk.empty() || p != NULL);
	}

	// 4. �������
	void LayerOrder(TreeNode* root) {
		TreeNode* p = root;
		queue<TreeNode*> q;
		q.push(p);  // �Ȱ�root��ӣ�Ȼ��ÿ����һ�Σ���front�������ӽڵ����
		while (!q.empty()) {
			TreeNode* front = q.front();
			q.pop(); cout << front->val << " ";
			if (front->left != NULL) q.push(front->left);
			if (front->right != NULL) q.push(front->right);
		}
	}
};

class Solution {
public:
	// ����ǰ���������������������������
	// ˼·������ǰ��ĵ�һ��Ԫ�أ�һ��Ϊroot�����������ҵ���root�����Ԫ��Ϊ���������Ҳ�Ϊ���������ݹ鼴��
	TreeNode* Construct(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.size() != inorder.size() || preorder.size() == 0) return NULL;
		return ConstructHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
	TreeNode* ConstructHelper(vector<int> &preorder, vector<int> &inorder, int s1, int e1, int s2, int e2) {
		// ��preoder������[s1 e1]��inoder������[s2 e2]����������
		TreeNode* root = new TreeNode(preorder[s1]);
		if (s1 == e1 && s2 == e2) return root;
		int rootinorder = s2;
		for (; preorder[s1] != inorder[rootinorder]; rootinorder++);  // ��inorder���ҵ�root��λ��
		int left_length = rootinorder - s2;
		// �����������ֱ�ݹ�
		if (rootinorder > s2) root->left = ConstructHelper(preorder, inorder, s1 + 1, s1 + left_length, s2, rootinorder - 1);
		if (rootinorder < e2) root->right = ConstructHelper(preorder, inorder, s1 + left_length + 1, e1, rootinorder+1, e2);
		return root;
	}
};

// ����ǰ������ķ�������������
TreeNode* MakeTree(int* a, int size, int& index, int& invalid) {
	TreeNode* root = NULL;
	if (index < size && a[index] != invalid) {
		root = new TreeNode(a[index]);
		root->left = MakeTree(a, size, ++index, invalid);
		root->right = MakeTree(a, size, ++index, invalid);
	}
	return root;
}

void main_traverse() {
	//�ø��ֱ����㷨���в���
	
	// ���ɶ�����
	int a[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int invalid = '#';
	int size = sizeof(a) / sizeof(a[0]);
	int begin = 0;
	TreeNode* root = MakeTree(a, size, begin, invalid);

	Traverse so;
	cout << "ǰ��������" << endl;
	so.PreOrder(root); cout << endl;
	cout << "ǰ��ǵݹ飺" << endl;
	so.PreOrder2(root); cout << endl << endl;

	cout << "����������" << endl;
	so.InOrder(root); cout << endl;
	cout << "����ǵݹ飺" << endl;
	so.InOrder2(root); cout << endl << endl;

	cout << "����������" << endl;
	so.PostOrder(root); cout << endl;
	cout << "����ǵݹ飺" << endl;
	so.PostOrder2(root); cout << endl << endl;

	cout << "����������" << endl;
	so.LayerOrder(root); cout << endl << endl;
}

void main() {
	// ��ǰ��+�������ɶ������������б�������
	vector<int> preorder{ 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inorder{ 4, 7, 2, 1, 5, 3, 8, 6 };
	Solution so1;
	Traverse so2;
	TreeNode* root = so1.Construct(preorder, inorder);
	cout << "ǰ��������" << endl;
	so2.PreOrder(root); cout << endl;
}
