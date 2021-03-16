//complexity: O(logN)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>a, int left, int right, int x)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (x == a[mid])
			return mid;
		else if (x < a[mid])
			right = mid - 1;
		else if (x > a[mid])
			left = mid + 1;
	}
	return -1;
}
int binarySearchRecursion(vector<int>a, int left, int right, int x)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binarySearchRecursion(a, left, mid - 1, x);
		return binarySearchRecursion(a, mid + 1, right, x);
	}
	return -1;
}
int bsFirst(vector<int> & a, int left, int right, int x)//timphantudautien	
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		if ((mid == left || x > a[mid - 1]) && a[mid] == x)
			return mid;
		else if (x > a[mid])
			return bsFirst(a, mid + 1, right, x);
		else
			return bsFirst(a, left, mid - 1, x);
	}
	return -1;
}
int bsFirst(vector<int> & a, int left, int right, int x)//timphantucuoicung	
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		if ((mid == left || x < a[mid - 1]) && a[mid] == x)
			return mid;
		else if (x > a[mid])
			return bsFirst(a, mid + 1, right, x);
		else
			return bsFirst(a, left, mid - 1, x);
	}
	return -1;
}
int lowerBound(vector<int>a, int x){
    int l = 0, r = a.size(), pos = r;
    while(l<r){
        int m = (r - l) / 2 + l;
        if(a[m] >= x ){
            pos = m;
            r = m;
        }else
            l = m + 1;
    }
    return pos;
}

int upperBound(vector<int>a, int x){
    int l = 0, r = a.size(), pos = r;
    while(l<r){
        int m = (r - l) / 2 + l;
        if(a[m] > x ){
            pos = m;
            r = m;
        }else
            l = m + 1;
    }
    return pos;
}

int main()
{
	vector<int>a;
	int n, x, value;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		a.push_back(value);
	}
	int result = binarySearch(a, 0, n - 1, x);
	cout << result;
	return 0;
	//dung thu vien
	int b[] = { 1,1,2,2,2,3,3,4,5,7 };
	vector<int>v;
	int n = 9;
	for (int i = 0; i < n; i++)
	{
		v.push_back(a[i]);
	}
	bool result = binary_search(v.begin(), v.end(), x);//tra ve gia tri dung/sai

	vector<int>::iterator low_value;
	low_value = lower_bound(v.begin(), v.end(), x);//tim can duoi >=
	int index = low_value - v.begin();

	vector<int>::iterator upp_value;
	int index = upp_value - v.begin();
}

