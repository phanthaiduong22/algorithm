#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;


//khai bao cau truc mot node trong BST O(1)
struct Node
{
	int key;
	Node* left;
	Node* right;
};
//tao mot node moi O(1)
Node* createNode(int x)
{
	Node* newnode = new Node;
	newnode->key = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}
//chen mot node vao trong BST O(h)
Node* insertNode(Node* root, int x)
{
	if (root == NULL)
		return createNode(x);
	if (x < root->key)
		root->left = insertNode(root->left, x);
	else if (x > root->key)
		root->right = insertNode(root->right, x);
	return root;
}
//tao cay BST O(N*h)	
void createTree(Node * &root, int a[], int n)
{
	for (int i = 0; i < n; i++)
		root = insertNode(root, a[i]);
}
//tim kiem mot node O(h) worstcase O(n)
Node* searchNode(Node * root, int x)
{
	if (root == NULL || root->key == x)
		return root;
	if (root->key < x)
		return searchNode(root->right, x);
	return searchNode(root->left, x);
}
//xoa mot node O(h) worst case O(n)
Node* minValueNode(Node * node)
{
	Node* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
Node* deleteNode(Node * &root, int x)
{
	if (root == NULL)
		return root;
	if (x < root->key)
		root->left = deleteNode(root->left, x);
	else if (x > root->key)
		root->right = deleteNode(root->right, x);
	else
	{
		if (root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
//duyet cay BST	
void traversalTree(Node * root)
{
	if (root != NULL)
	{
		traversalTree(root->left);
		cout << root->key << " ";
		traversalTree(root->right);
	}
}
int main()
{
	int x, n;
	set<int>s;
	map<int, string>m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s.insert(x);
	}
	int j;
	string p;
	for (int i = 0; i < n; i++)
	{
		cin >> j >> p;
		pair<int, string>a{j, p};
		m.insert(a);
	}
	set<int>::iterator it;
	map<int, string>::iterator it1;
	add();//them phan tu
	find();//tim phan tu
	erase();//xoa mot phan tu
	lower_bound();//tim can duoi
	upper_bound();//tim can tren
	size();
	empty();
	clear();
	swap();
}