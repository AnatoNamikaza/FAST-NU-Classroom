#include <iostream>
#include<vector> 
using namespace std;

template <typename k, typename v>
class BST{
template <typename k, typename v>
struct TNode
{
	 k key;
	 v value;
	 TNode<k, v> *leftChild;
	 TNode<k, v> *rightChild;
	 TNode(){
		leftChild = nullptr;
		rightChild = nullptr;
	 }

	  TNode(k key, v value){
		  this->key = key;
		  this->value = value;
		leftChild = nullptr;
		rightChild = nullptr;
	 }
};
TNode<k,v> *root;
public:
	//Methods
	BST():root(NULL){}     //set root to null
	BST(BST<k,v> & obj){
		root = new TNode<int,int>();
		preorder_insert(obj.root);
	} //copy constructor

		void preorder_insert(TNode<k,v> *root1){
		if(root1 == NULL) return;
		else{
			this->insertRec(root1->key,root1->value);
		 preorder_insert(root1->leftChild);
		 preorder_insert(root1->rightChild);
			
		}
	}
	
	BST(TNode<int,int> *root){
	this->root = root;
	}
	void insertRec(k const  key, v const value){
		root = recursive_insert(root, key,value);

	}    /*insert element in the bst. No duplication allowed.*/      
	void print(){
		if(root != nullptr)
			inorder(this->root);
	} /*Print the BST values only not keys using recursive in-order traversal*/
	BST operator +(BST & b1){
		TNode <int,int> *new_tree = new TNode<int,int>();
		preorder_addition(new_tree,this->root,b1.root);

	};  /* operator such that it merges two binary trees. Each node in the new tree should hold a value equal to the sum of the values of the corresponding nodes of the input trees. If only one input tree has a node in a given position, the corresponding node in the new tree should match that input node. Corresponding key values are also added.*/
	
	BST find_BST_lessthan_integer_c(int c){
	// search int c
	// deep copy parent of c
	TNode<int,int> *parent = root;
	TNode<int,int> *current = root;
	while(current != NULL){
		if(current->key < root->key){
			// move left
			parent = current;
			current = current->leftChild;
		}
		else{
			parent = current;
			current = current->rightChild;
		}
	}
	// parent is pointing at node to be deep copied
		if(parent != NULL){
		TNode<int,int> *new_copy = new TNode<int,int>(parent);
		this->root = BST<int,int>(new_copy);
		}
		
	}  /* that create a new tree that has all nodes whose keys are less than or equal to integer c in the given tree, maintaining the tree structure of the BST and returns it. You can assume that integer c will be one of the node's key in the BST. */                                                             
	
	TNode<k,v>* recursive_insert(TNode<k,v> *root, k key, v value){
		if(root == nullptr){
			TNode<k,v> *new_node = new TNode<k,v>(key,value);
			return new_node;
		}
		else{
			// tree already exists
			if(key > root->key) root->rightChild = recursive_insert(root->rightChild,key,value);
			else{root->leftChild = recursive_insert(root->leftChild,key,value);}
		}
		return root;
	}

	void inorder(TNode <k,v> *root){
		if(root == NULL) {return;}
		else{
			inorder(root->leftChild);
			cout << root->value << " " << endl;
			inorder(root->rightChild);
		}
		return;
	}

	void postorder_delete(TNode<k,v> *root){
		if(root== NULL) return;
		else{
			postorder_delete(root->leftChild);
			postorder_delete(root->rightChild);
			delete root;

		}
	}
	~BST(){
		postorder_delete(root);
		root = NULL;
	};     //clean up memory
};


//template <typename k,typename v>
//class A{
//	template <typename k,typename v>
//	struct B{}; B<k,v>*root;
//};

int main()
{
		BST <int,int> s1;
    s1.insertRec(3,100);
   s1.insertRec(1,200);
    s1.insertRec(4,50);
	s1.insertRec(2,765);
	s1.insertRec(5,34);
	s1.print(); //prints 200 765 100 50 34
    BST <int,int> s2;
    s2.insertRec(1,99);
    s2.insertRec(9,56);
    s2.insertRec(5,60);
	s2.insertRec(10,8);
	s2.print(); //prints 99 60 56 8

	//BST <int,int> s3=s1+s2;
	//s3.print();  // prints 200 765 199 60 106 42
	//BST <int,int> s4=s3+s3;
	//s4.print(); // prints 400 1530 398 120 212 84
	//BST <int,int> s5=s1.find_BST_lessthan_integer_c(2);
	//s5.print(); //prints 200 765
	//BST <int,int> s6=s2.find_BST_lessthan_integer_c(9);
	//s6.print(); //prints 99 60 56
	

	system("pause");
	return 0;
}

