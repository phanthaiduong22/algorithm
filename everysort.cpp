#include <bits/stdc++.h>

using namespace std;

void selectionsort(vector<int> &a){
    int n = a.size();
    for(int i = 0;i<n; ++i){
        int min_idx = i;
        for(int j = i;j<n; ++j){
            if(a[min_idx] > a[j])
                min_idx = j;
        }
        swap(a[min_idx], a[i]);
    }
}

void bubblesort(vector<int> &a){
    int n = a.size(); //swap(a[j], a[j + 1])
    for(int i = 0;i<n; ++i){
        int swapped = 0;
        for(int j = 0;j<n - i - 1; ++j){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                swapped = 1;
            }
        }
        if(swapped == 0)
            return;
    }
}

void insertionsort(vector<int> & a){
    int n = a.size();
    for(int i = 1;i<n; ++i){
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}

void quicksort(vector<int>&a, int left, int right){
    int left_arrow, right_arrow, pivot;
    left_arrow = left;
    right_arrow = right;
    pivot = a[(right + left) / 2];
    do{
        while(a[left_arrow] < pivot)
            left_arrow++;
        while(a[right_arrow] > pivot)
            right_arrow--;
        if(left_arrow <right_arrow){
            swap(a[left_arrow], a[right_arrow]);
            left_arrow++;
            right_arrow--;
        }
    }while(left_arrow<=right_arrow);
    if(left < right_arrow)
        quicksort(a, left, right_arrow);
    if(left_arrow < right);
        quicksort(a, left_arrow, right);
}

void mergesort(vector<int> &a, int l, int r){
    if(l>=r)
        return;
    int m = (r + l) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    int *temp = new int [r - l + 1];
    int i = l, j = m + 1, k = 0;

    // a[l...mid] a[mid + 1...r]

    while(i<=m && j <= r){
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<=m)
        temp[k++] = a[i++];
    while(j<=r)
        temp[k++] = a[j++];
    
    k = 0;
    for(int i = l; i<=r; ++i){
        a[i] = temp[k++];
    }

    delete[] temp;
}

int main(){
    vector<int> a = { 3, 2, 4, 5, 1, 6, 7};
    mergesort(a, 0, a.size() - 1);
    for(int i : a)
        cout<<i<<" ";
}