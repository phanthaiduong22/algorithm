//Xay dung heap
#include <iostream>
#include <vector>

using namespace std;
vector<int>h;

void swap(int& x, int& y) {
	int z = x;
	x = y;
	y = z;
}
void MinHeapify(int i) {
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < h.size() && h[left] < h[smallest])
		smallest = left;
	if (right < h.size() && h[right] < h[smallest])
		smallest = right;
	if (smallest != i) {
		swap(h[i], h[smallest]);
		MinHeapify(smallest);
	}
}
void buildHeap(int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		MinHeapify(i);
	}
}
int top() {
	return h[0];
}
void push(int value)//==insert
{
	h.push_back(value);
	int i = h.size() - 1;
	while (i != 0 && h[(i - 1) / 2] > h[i]) {
		swap(h[i], h[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}
void pop() {//==delete	
	int length = h.size();
	if (length == 0) {
		return;
	}
	h[0] = h[length - 1];
	h.pop_back();
	MinHeapify(0);
}
void deleteKey(int i) {
	swap(h[i], h[h.size() - 1]);
	h.resize(h.size() - 1);
	MinHeapify(0);
}
void printf() {
	for (int i = 0; i < h.size(); i++)
		cout << h[i] << " ";
}
int main()
{
	vector<int>a = { 40,100,50,40,15,30,10 };
	h = a;
	buildHeap(h.size());
	deleteKey(0);
	printf();
	return 0;
}