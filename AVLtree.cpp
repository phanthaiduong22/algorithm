#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
	int height;
};
int max(int a, int b) {
	return a > b ? a : b;
}
int Height(Node* N) {
	if (N == NULL)
		return 0;
	return N->height;
}

Node* newNode(int key) {
	Node* node = new Node;
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}
int getBalance(Node * N) {
	if (N == NULL)
		return 0;
	return (Height(N->left) - Height(N->right));
}
Node * leftRotate(Node * root) {
	Node* x = root->left;
	Node* temp = x->right;
	//perform rotate
	x->right = root;
	x->left = temp;
	//update height
	root->height = max(Height(root->left), Height(root->right)) + 1;
	x->height = max(Height(x->left), Height(x->right)) + 1;

	return x;
}
Node* rightRotate(Node * root) {
	Node* x = root->right;
	Node* temp = x->left;
	//perform rotate
	x->right = root;
	x->left = temp;
	//update height
	root->height = max(Height(root->left), Height(root->right)) + 1;
	x->height = max(Height(x->left), Height(x->right)) + 1;

	return x;

}
Node* insertAVL(Node * root, int key) {
	if (root == NULL) {
		return newNode(key);
	}
	else if (key < root->key) {
		root->left = insertAVL(root->left, key);
	}
	else if (key > root->key) {
		root->right = insertAVL(root->right, key);
	}
	else
		return root;
	int balance = getBalance(root);
	//left left rotation
	if (balance > 1 && key < root->left->key) {
		return rightRotate(root);
	}
	//right right rotation
	else if (balance < -1 && key > root->right->key) {
		return leftRotate(root);
	}
	else if (balance > 1 && key > root->left->key) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	else if (balance < -1 && key < root->right->key) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void preOrder(Node * root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main() {

	Node* root = NULL;

	root = insertAVL(root, 10);
	root = insertAVL(root, 20);
	root = insertAVL(root, 30);
	root = insertAVL(root, 40);
	root = insertAVL(root, 50);
	root = insertAVL(root, 25);
	cout << "Cay nhi phan tim kiem bang (AVL):" << endl;
	preOrder(root);
	return 0;
}