#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
//QUADRATIC PROBING (PHUONG PHAP DO BAC 2)
const int TABLE_SIZE = 1e6 + 3;

struct Node {
	string key;
	int marker = 0;
};

int current_size;
Node* hashTable;

unsigned int polyHash(string keys)
{
	unsigned int hashValue = 0;
	unsigned int a = 33;
	for (int i = 0; i < keys.size(); i++)
		hashValue = (keys[i] + a * hashValue);
	return hashValue & 0x7FFFFFFF;
}

bool insertKey(string key) {
	unsigned int index = polyHash(key) % TABLE_SIZE;
	if (current_size >= TABLE_SIZE)
		return false;
	for (int i = 1; i <= TABLE_SIZE; i++) {
		if (hashTable[index].marker == 0) {
			hashTable[index].key = key;
			hashTable[index].marker = 1;
			current_size++;
			return true;
		}
		index = (index + (1LL * i * i) % TABLE_SIZE) % TABLE_SIZE;
	}
	return false;
}
int searchKey(string key)
{
	unsigned int index = polyHash(key) % TABLE_SIZE;
	int count = 0;
	if (current_size == 0)
		return -1;
	int i = 1;
	while (hashTable[index].marker != 0 && count <= TABLE_SIZE) {
		if (hashTable[index].key == key)
		{
			if (hashTable[index].marker == 1)
				return index;
			return -1;
		}
		index = (index + (1LL * i * i) % TABLE_SIZE) % TABLE_SIZE;
		count++;
		i++;
	}
	return -1;
}

int main()
{
	// freopen("words_alpha.txt", "r", stdin);

	hashTable = new Node[TABLE_SIZE];

	// string s;
	// while (cin >> s)
	// {
	// 	insertKey(s);
	// }
	// string words[10] = { "abadia", "treasonableness", "outstanding", "sturionine", "unloose", "unltraconservative",
	// 	"felsobanyite", "unperiphrastically", "fellowships", "canaliculization" };
	// cout << "QUADRATIC PROBING:" << endl;
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