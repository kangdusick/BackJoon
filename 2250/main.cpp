#include <iostream>
#include <map>
#include <vector>

using namespace std;

class TreeNode
{
public:
	int num = -1;
	int level = -1;
	TreeNode* root = nullptr;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};

map<int, TreeNode*> mapTreeNode;
map<int, vector<int>> level_Vector;
int JJ = 1;
//key: level, vector: 해당 레벨에 속하는 j들
void setLevel(TreeNode* treeNode)
{
	if (treeNode->root == nullptr)
	{
		treeNode->level = 1;
	}
	else
	{
		treeNode->level = treeNode->root->level + 1;
	}
	if (treeNode->left != nullptr)
		setLevel(treeNode->left);
	if (treeNode->right != nullptr)
		setLevel(treeNode->right);
}
void SetJ(TreeNode* treeNode)
{
	if (treeNode->left != nullptr)
		SetJ(treeNode->left);
	level_Vector[treeNode->level].push_back(JJ);
	JJ++;
	if (treeNode->right != nullptr)
		SetJ(treeNode->right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, rootNo, leftNo, rightNo;
	cin >> N;
	TreeNode* init;
	for (int i = 0; i < N; i++)
	{
		cin >> rootNo >> leftNo >> rightNo;
		if (mapTreeNode[rootNo] == nullptr)
		{
			TreeNode* addRoot = new TreeNode;
			addRoot->num = rootNo;
			mapTreeNode[rootNo] = addRoot;
		}
		if (leftNo != -1)
		{
			if (mapTreeNode[leftNo] == nullptr)
			{
				TreeNode* addLeft = new TreeNode;
				addLeft->num = leftNo;
				addLeft->root = mapTreeNode[rootNo];
				mapTreeNode[rootNo]->left = addLeft;
				mapTreeNode[leftNo] = addLeft;
			}
			else
			{
				mapTreeNode[rootNo]->left = mapTreeNode[leftNo];
				mapTreeNode[leftNo]->root = mapTreeNode[rootNo];
			}
		}
		if (rightNo != -1)
		{
			if (mapTreeNode[rightNo] == nullptr)
			{
				TreeNode* addRight = new TreeNode;
				addRight->num = rightNo;
				addRight->root = mapTreeNode[rootNo];
				mapTreeNode[rootNo]->right = addRight;
				mapTreeNode[rightNo] = addRight;
			}
			else
			{
				mapTreeNode[rootNo]->right = mapTreeNode[rightNo];
				mapTreeNode[rightNo]->root = mapTreeNode[rootNo];
			}
			
		}

	}
	init = mapTreeNode.begin()->second;
	while (init->root !=nullptr)
	{
		init = init->root;
	}
	setLevel(init);
	SetJ(init);
	int max = 0;
	int llevel = 0;
	map<int, vector<int>>::iterator iter = level_Vector.begin();
	map<int, vector<int>>::iterator iterEnd = level_Vector.end();
	while (iter != iterEnd)
	{
		int left = (iter->second).front();
		int right = (iter->second).back();
		int sol = right - left + 1;
		if (max < sol)
		{
			llevel = iter->first;
			max = sol;
		}
		iter++;
	}
	cout << llevel << " " << max;
	return 0;
}

/*
6
1 2 3
2 5 4
3 -1 6
4 -1 -1
5 -1 -1
6 -1 -1
답: 3 6

1
1 -1 -1
답: 1 1

3
2 3 -1
1 2 -1
3 -1 -1
답: 1 1


*/