#include <iostream>
#include <map>
using namespace std;

class Tree
{
public:
	char alpha = '.';
	Tree* left = nullptr;
	Tree* right = nullptr;
};
map<char, Tree*> rootList;
void SearchF(Tree* root)
{
	if (root->alpha != '.')
		cout << root->alpha;
	if (root->left != nullptr)
		SearchF(root->left);
	if (root->right != nullptr)
		SearchF(root->right);
}
void SearchM(Tree* root)
{

	if (root->left != nullptr)
		SearchM(root->left);
	if (root->alpha != '.')
		cout << root->alpha;
	if (root->right != nullptr)
		SearchM(root->right);
}
void SearchL(Tree* root)
{
	if (root->left != nullptr)
		SearchL(root->left);
	if (root->right != nullptr)
		SearchL(root->right);
	if (root->alpha != '.')
		cout << root->alpha;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	char root, left, right;
	cin >> N;
	Tree* A = new Tree;
	A->alpha = 'A';
	rootList['A'] = A;
	for (int i = 0; i < N; i++)
	{
		cin >> root >> left >> right;
		Tree* addLeft = new Tree;
		addLeft->alpha = left;
		Tree* addRight = new Tree;
		addRight->alpha = right;
		rootList[root]->left = addLeft;
		rootList[root]->right = addRight;
		rootList[left] = addLeft;
		rootList[right] = addRight;
	}
	SearchF(A);
	cout << "\n";
	SearchM(A);
	cout << "\n";
	SearchL(A);
	cout << "\n";
	return 0;
}