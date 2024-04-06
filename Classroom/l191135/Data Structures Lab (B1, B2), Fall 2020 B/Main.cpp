#include <iostream>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

template <typename k, typename v>
struct TNode {
	k key;
	v value;
	int nodeCount;
	TNode *left, *right;

	TNode(k key, v value) { this->key = key, this->value = value, nodeCount = 1, left = nullptr, right = nullptr; }
};


template <typename k, typename v>
class BinaryTree {
private:
	TNode<k, v> *root;

	void removeAll(TNode<k, v> *root) //no need to modify this function
	{
		if (!root) return;

		removeAll(root->left);
		removeAll(root->right);
		delete root;
	}

public:
	BinaryTree() //no need to modify constructor
	{
		this->root = nullptr;
	}

	void insert(k const key, v const value) {
		//implement here.
		if (!root) { root = new TNode<k, v>(key, value); }
		else { insertinTree(key, value, root); }
	}

	void insertinTree(k const key, v const value, TNode<k, v> *&temp) {
		if (!temp->left) { temp->left = new TNode<k, v>(key, value); }
		else if (temp->left && !temp->right) { temp->right = new TNode<k, v>(key, value); }
		else if (temp->left && temp->right && abs(temp->left->nodeCount - temp->right->nodeCount) <= 1) {
			insertinTree(key, value, temp->left);
		}
		else
			insertinTree(key, value, temp->right);
		temp->nodeCount++;
	}

	bool isPerfect() const {
		if (!root) { return true; }
		else if (root->nodeCount == (pow(2, MaxHeight(root) + 1) - 1)) { return true; }
		else { return false; }
	}

	int MaxHeight(TNode<k, v> *temp) const {
		if (!temp) { return -1; }
		else if (MaxHeight(temp->left) > MaxHeight(temp->right)) { return MaxHeight(temp->left) + 1; }
		else { return MaxHeight(temp->right) + 1; }
	}

	bool search(k const key) const {
		return searchTree(key, root); //replace this line with your implementation
	}

	bool searchTree(k key, TNode<k, v> *temp) const {
		if (temp && temp->key == key) { return true; }
		if (temp && temp->left && searchTree(key, temp->left)) { return true; }
		if (temp && temp->right && searchTree(key, temp->right)) { return true; }
		return false;
	}

	~BinaryTree()//no need to modify destructor
	{
		this->removeAll(this->root);

	}

};


//################main function###################
int main()
{
	BinaryTree<int, int> tree1;
	tree1.insert(10, 10);
	tree1.insert(2, 2);
	tree1.insert(0, 0);
	tree1.insert(3, 3);
	tree1.insert(1, 1);
	tree1.insert(10, 10);

	BinaryTree<int, int> tree2;
	tree2.insert(3, 3);
	tree2.insert(23, 23);
	tree2.insert(15, 15);


	cout << "is Binary Tree 1 a perfect binary tree? " << tree1.isPerfect() << endl << endl;
	cout << "is Binary Tree 2 a perfect binary tree? " << tree2.isPerfect() << endl << endl;


	if (tree1.search(3))
	{
		cout << "3 found from tree 1" << endl << endl;
	}

	if (!tree2.search(12))
	{
		cout << "12 not found from tree2." << endl << endl;

	}


	system("pause");
}