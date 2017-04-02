#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
	int key;
	int left;
	int right;

	Node() : key(0), left(-1), right(-1) {}
	Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};
vector<Node> tree;
vector<int>* inOrderTraversal(int index){
	static vector<int>result;
	if (index == -1)
		return NULL;
	inOrderTraversal(tree[index].left);
	result.push_back(tree[index].key);
	inOrderTraversal(tree[index].right);
	return &result;
}


bool IsBinarySearchTree(const vector<Node>& tree) {
	if (tree.size() == 0)
		return true;
	vector<int>*treeOrdered = inOrderTraversal(0);
	int first = (*treeOrdered)[0];
	for (int i = 1; i < (*treeOrdered).size(); ++i)
	{
		if ((*treeOrdered)[i] < first)
			return false;
		else{
			first = (*treeOrdered)[i];
		}
	}
	return true;
}

int main() {
	int nodes;
	cin >> nodes;

	for (int i = 0; i < nodes; ++i) {
		int key, left, right;
		cin >> key >> left >> right;
		tree.push_back(Node(key, left, right));
	}
	if (IsBinarySearchTree(tree)) {
		cout << "CORRECT" << endl;
	}
	else {
		cout << "INCORRECT" << endl;
	}
	//system("pause");
	return 0;
}
