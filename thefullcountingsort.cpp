#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    freopen("thefullcountingsort.inp","r",stdin);
    freopen("thefullcountingsort.out","w",stdout);
    int n;
    cin >> n;
    vector<int> result(105, 0);
    vector<vector<string>>a;
    a.assign(105,vector<string>());
    for (int i = 0; i < n; i++)
    {
        int x;
        string s;
        cin >> x >> s;
        result[x]++;
        if (i < n / 2)
            a[x].push_back("-");
        else
        {
            a[x].push_back(s);
        }
    }
    for(int i=0;i<100;i++)
        {
            for(int j=0;j<result[i];j++)
                cout<<a[i][j]<<" ";
        }
        {
            fdfaf
        }
}