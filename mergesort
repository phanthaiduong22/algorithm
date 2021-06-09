#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& a, int l, int r, int m){
    int i = l, j = m + 1, k = 0;
    vector<int> c;
    while(i<=m  && j<=r){
        if(a[i] < a[j]){
            c.push_back(a[i++]);
        }else{
            c.push_back(a[j++]);
        }
    }
    while(i<=m){
        c.push_back(a[i++]);
    }
    while(j<=r){
        c.push_back(a[j++]);
    }
    for(int i = l;i<=r; ++i){
        a[i] = c[k++];
    }
}


void mergesort(vector<int>&a, int l, int r){
    if(l<r){
        int m = (r + l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);

        merge(a, l, r, m);
    }
}


int main(){
    vector<int> a = {5, 3, 2, 7, 8, 9, 1};
    mergesort(a, 0, a.size() - 1);
    for(int i : a)
        cout<<i<<" ";
}
