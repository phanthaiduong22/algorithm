#include <string>
#include <iostream>

using namespace std;

#define MAX 26	

struct node
{
	struct node* child[MAX];
	int countWord;
};
//them tu O(string_lengh)
struct node* newNode()
{
	struct node* Node = new struct node;
	Node->countWord = 0;
	for (int i = 0; i < MAX; i++)
	{
		Node->child[i] = NULL;
	}
	return Node;
}
void addWord(struct node* root, string s)
{
	int ch;
	struct node* temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
		{
			temp->child[ch] = newNode();
		}
		temp = temp->child[ch];
	}
	temp->countWord++;
}
//tim tu
bool findWord(struct node* root, string s)
{
	int ch;
	struct node* temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
		{
			return false;
		}
		temp = temp->child[ch];
	}
	return temp->countWord > 0;
}
//xoa tu trong cay
bool isWord(struct node* pNode)
{
	return (pNode->countWord != 0);
}
bool isEmpty(struct node* pNode)
{
	for (int i = 0; i < MAX; i++)
	{
		if (pNode->child[i] != NULL)
		{
			return false;
		}
	}
	return true;
}
bool removeWord(struct node* root, string s, int level, int len)
{
	if (!root)
		return false;
	int ch = s[level] - 'a';
	if (level == len)
	{
		if (root->countWord > 0)
		{
			root->countWord--;
			return true;
		}
		return false;
	}
	int flag = removeWord(root->child[ch], s, level + 1, len);
	if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch]))
	{
		delete root->child[ch];
		root->child[ch] = NULL;
	}
	return flag;
}
//print
void printWord(struct node* root, string s)
{
	if (isWord(root))
	{
		cout << s << endl;
	}
	for (int i = 0; i < MAX; i++)
	{
		if (root->child[i])
		{
			printWord(root->child[i], s + ('a' + i));
		}
	}
}
//main
int main()
{
	struct node* root = newNode();
	addWord(root, "the");
	addWord(root, "then");
	addWord(root, "bigo");

	cout << findWord(root, "there") << endl;
	cout << findWord(root, "th") << endl;
	cout << findWord(root, "the") << endl;

	removeWord(root, "bigo", 0, 4);
	removeWord(root, "the", 0, 3);
	removeWord(root, "then", 0, 4);
	return 0;
}