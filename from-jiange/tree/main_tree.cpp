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

// 二叉树各种遍历算法
class Traverse {
public:
	// 1. 前序遍历（root, left, right）
	void PreOrder(TreeNode* root) {
		if (root != NULL) {
			cout << root->val << " ";
			PreOrder(root->left);
			PreOrder(root->right);
		}
	}
	// 非递归
	void PreOrder2(TreeNode* root) {
		TreeNode* p = root;
		stack<TreeNode*> stk;
		do {
			while (p != NULL) {  // 搜至最左结点，入栈，打印
				stk.push(p);
				cout << p->val << " ";
				p = p->left;
			}
			if (!stk.empty()) {  // 出栈，并指向右结点
				p = stk.top(); stk.pop();
				p = p->right;
			}
		} while (!stk.empty() || p != NULL);  // 栈不空或者当前节点不空，则继续循环
	}

	// 2. 中序遍历（left, root, right）
	void InOrder(TreeNode* root) {
		if (root != NULL) {
			InOrder(root->left);
			cout << root->val << " ";
			InOrder(root->right);
		}
	}
	// 非递归
	void InOrder2(TreeNode* root) {
		TreeNode* p = root;
		stack<TreeNode*> stk;
		do {
			while (p != NULL) {  // 搜至最左结点，入栈
				stk.push(p);
				p = p->left;
			}
			if (!stk.empty()) {
				p = stk.top(); stk.pop(); 
				cout << p->val << " ";  // 打印
				p = p->right;
			}
		} while (!stk.empty() || p != NULL);

	}

	// 3. 后序遍历（left, right, root）
	void PostOrder(TreeNode* root) {
		if (root != NULL) {
			PostOrder(root->left);
			PostOrder(root->right);
			cout << root->val << " ";
		}
	}
	// 非递归
	void PostOrder2(TreeNode* root) {
		TreeNode* p = root;
		TreeNode* prev = NULL;  // 记录上次访问过的节点
		stack<TreeNode*> stk;
		do {
			while (p != NULL) {
				stk.push(p);
				p = p->left;
			}
			TreeNode* top = stk.top();
			// 如果右树为空或者已经访问过，则访问当前节点，并出栈
			// 否则访问右子树
			if (top->right == NULL || top->right == prev) {
				cout << top->val << " ";
				prev = top;
				stk.pop();
			}
			else p = top->right;
		} while (!stk.empty() || p != NULL);
	}

	// 4. 层序遍历
	void LayerOrder(TreeNode* root) {
		TreeNode* p = root;
		queue<TreeNode*> q;
		q.push(p);  // 先把root入队，然后每出队一次，将front的左右子节点入队
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
	// 根据前序和中序遍历结果，构建出二叉树
	// 思路：对于前序的第一个元素，一定为root，在中序中找到该root，左侧元素为左子树，右侧为右子树，递归即可
	TreeNode* Construct(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.size() != inorder.size() || preorder.size() == 0) return NULL;
		return ConstructHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
	TreeNode* ConstructHelper(vector<int> &preorder, vector<int> &inorder, int s1, int e1, int s2, int e2) {
		// 对preoder的区间[s1 e1]和inoder的区间[s2 e2]构建二叉树
		TreeNode* root = new TreeNode(preorder[s1]);
		if (s1 == e1 && s2 == e2) return root;
		int rootinorder = s2;
		for (; preorder[s1] != inorder[rootinorder]; rootinorder++);  // 在inorder中找到root的位置
		int left_length = rootinorder - s2;
		// 对左右子树分别递归
		if (rootinorder > s2) root->left = ConstructHelper(preorder, inorder, s1 + 1, s1 + left_length, s2, rootinorder - 1);
		if (rootinorder < e2) root->right = ConstructHelper(preorder, inorder, s1 + left_length + 1, e1, rootinorder+1, e2);
		return root;
	}
};

// 按照前序遍历的方法构建二叉树
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
	//用各种遍历算法进行测试
	
	// 生成二叉树
	int a[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int invalid = '#';
	int size = sizeof(a) / sizeof(a[0]);
	int begin = 0;
	TreeNode* root = MakeTree(a, size, begin, invalid);

	Traverse so;
	cout << "前序搜索：" << endl;
	so.PreOrder(root); cout << endl;
	cout << "前序非递归：" << endl;
	so.PreOrder2(root); cout << endl << endl;

	cout << "中序搜索：" << endl;
	so.InOrder(root); cout << endl;
	cout << "中序非递归：" << endl;
	so.InOrder2(root); cout << endl << endl;

	cout << "后序搜索：" << endl;
	so.PostOrder(root); cout << endl;
	cout << "后序非递归：" << endl;
	so.PostOrder2(root); cout << endl << endl;

	cout << "层序搜索：" << endl;
	so.LayerOrder(root); cout << endl << endl;
}

void main() {
	// 由前序+中序生成二叉树，并进行遍历测试
	vector<int> preorder{ 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inorder{ 4, 7, 2, 1, 5, 3, 8, 6 };
	Solution so1;
	Traverse so2;
	TreeNode* root = so1.Construct(preorder, inorder);
	cout << "前序搜索：" << endl;
	so2.PreOrder(root); cout << endl;
}
