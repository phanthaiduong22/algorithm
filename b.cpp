#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long long n, m, p;
int k;

vector<long long> a, b;
void printResult() { // hàm dùng để in một cấu hình ra ngoài
    for(int i = 1 ; i <=k ; i++) {
        cout<<b[i]<<" " ;
    }
    cout<<endl ;
}
void backtrack(int i)
{ // hàm quay lui
    for (int j =b[i - 1] + 1; j <= m - k + i; j++)
    {             // xét các khả năng của j
        b[i] = j; // ghi nhận một giá trị của j
        if (i == k)
        { // nếu cấu hình đã đủ k phần tử
            // in một cấu hình ra ngoài
            printResult();
        }
        else
        {
            backtrack(i + 1); // quay lui
        }
    }
}
void toHop()
{ // hàm liệt kê các tổ hợp
    if (k >= 0 && k <= m)
    {
        a[0] = 0; // khởi tạo giá trị a[0]
        backtrack(1);
    }
    else
    {
    }
}
int main()
{
    freopen("b.inp", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        b.push_back(x);
    }
    toHop();
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long min = 0;
        for (int j = 0; j < m; j++)
        {
            if (abs(a[i] - b[j]) < min)
                min = abs(a[i] - b[j]);
        }
        ans += min;
    }
}