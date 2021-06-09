#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>&a, int l, int r){
    int pivot = a[r];

    int i = l - 1;
    for(int j = l; j<= r- 1; ++j){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i + 1;
}

void quicksort(vector<int>&a, int l, int r){
    if(l<r){
        int pivot = partition(a, l, r);
        quicksort(a, l, pivot - 1);
        quicksort(a, pivot + 1, r);
    }
}

int main(){
    vector<int>a = {4, 3, 5, 7, 2, 1, 3, 7};
    quicksort(a, 0, a.size() - 1);   
    for(int i : a)
        cout<<i<<" ";
}
