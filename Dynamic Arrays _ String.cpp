#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int>a;
	a.push_back(5);
	int result = a.front();	//a[0];
	int result1 = a.back(); //a[n-1]
	vector<int>::iterator it;
	it = a.begin() + 2;
	a.insert(it, 9);
	a.pop_back();
	vector<int>::iterator it1;
	it1 = a.begin() + 2;
	a.erase(it1);
	a.clear();
	int l = a.size();
	a.resize(7);
	a.empty();
	for (int i = 0; i < a.size(); i++)
		cout << a[i];
	vector<int>::iterator it2;
	for ( it2 = a.begin(); it2 != a.end(); it2++)
		cout << *it2 << " ";
	
}