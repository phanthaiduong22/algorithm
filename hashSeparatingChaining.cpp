#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
using namespace std;
//SEPARATE CHAINING (PHUONG PHAP KET NOI)
const int TABLE_SIZE = 1e6 + 3;

struct Node {
	string key;
	Node* next;
};

struct HashTable {
	Node* head = NULL;
	int count = 0;
};

HashTable* hashTable;

Node* createNode(string key)
{
	Node* newNode = new Node();
	newNode->key = key;
	newNode->next = NULL;
	return newNode;
}

unsigned int polyHash(string keys)
{
	unsigned int hashValue = 0;
	unsigned int a = 33;
	for (int i = 0; i < keys.size(); i++)
		hashValue = (keys[i] + a * hashValue);
	return hashValue & 0x7FFFFFFF;
}

void insertKey(string key) {
	unsigned int index = polyHash(key) % TABLE_SIZE;
	Node* newNode = createNode(key);
	if (!hashTable[index].head)
	{
		hashTable[index].head = newNode;
		hashTable[index].count = 1;
		return;
	}
	newNode->next = hashTable[index].head;
	hashTable[index].head = newNode;
	hashTable[index].count++;
}
bool searchKey(string key)
{
	unsigned int index = polyHash(key) % TABLE_SIZE;
	Node* myNode = hashTable[index].head;
	while (myNode != NULL)
	{
		if (myNode->key == key)
			return true;
		myNode = myNode->next;
	}
	return false;
}

int main()
{
    hashTable = new HashTable[TABLE_SIZE];
	//freopen("words_alpha.txt", "r", stdin);
	// string s;
	// while (cin >> s)
	// {
	// 	insertKey(s);
	// }
	// string words[10] = { "abadia", "treasonableness", "outstanding", "sturionine", "unloose", "unltraconservative",
	// 	"felsobanyite", "unperiphrastically", "fellowships", "canaliculization" };
	// cout << "SEPARATE CHAINING:" << endl;
	// for (int i = 0; i < 10; i++)
	// {
	// 	auto start = std::chrono::high_resolution_clock::now();
	// 	searchKey(words[i]);
	// 	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	// 	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	// 	cout << microseconds << " micro seconds: " << words[i] << endl;
	// }
	// return 0;
}