#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
//
void selectionSort(vector<int>& arr, int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}
}
//
void bubbleSort(vector<int>& arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
//
void insertionSort(vector<int>& arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
//
void merge(vector<int>& arr, int l, int m, int r)
{
	int i = l, j = m + 1, k = 0;
	int temp[50000];
	while (i <= m || j <= r)
	{
		if (i > m)
			temp[k++] = arr[j++];
		else if (j > r)
			temp[k++] = arr[i++];
		else if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	for (int p = 0; p < k; p++)
		arr[l + p] = temp[p];
}

void mergeSort(vector<int>& arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
//
void quicksort(vector<int>& a, int left, int right)
{
	int l = left, r = right;
	int pivot = a[(l + r) / 2];
	do
	{
		while (a[l] < pivot) l++;
		while (a[r] > pivot) r--;
		if (l <= r)
		{
			swap(a[l], a[r]);
			l++;
			r--;
		}
	} while (l <= r);
	if (left < r)
		quicksort(a, left, r);
	if (l < right)
		quicksort(a, l, right);
}
//
void heapify(vector<int>& arr, int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector<int>& arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
//
int getMax(vector<int>& arr, int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}
void countSort(vector<int>& arr, int n, int exp)
{
	vector<int>output(n);
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
void radixsort(vector<int>& arr, int n)
{
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
//
int shellSort(vector<int>& arr, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	return 0;
}
//
int binarySearch(vector<int>& a, int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}

void binaryinsertionSort(vector<int>& a, int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];
		loc = binarySearch(a, selected, 0, j);
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}
//
void CocktailSort(vector<int>&a, int n)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;
	while (swapped) {
		swapped = false;
		for (int i = start; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;
		--end;
		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}
//
void interchangeSort(vector<int>& a,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[j], a[i]);
	}
}
int main()
{

	int n = 10000;
	srand(time(NULL));
	int t = 10;
	while (t--)
	{
		vector<int> a;
		for (int i = 0; i < n; i++)
		{
			int x = rand();
			a.push_back(x);
		}
		clock_t start = clock();
		interchangeSort(a, n);
		//for (int i = 0; i < n; i++)
		//	cout << a[i] << " ";
		//cout << endl;
		printf("%.2f\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	}
}