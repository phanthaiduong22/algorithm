#include <iostream>
#include <vector>

using namespace std;
#define MAX 30000
int parent[MAX + 5];
int ranks[MAX + 5];
int d[MAX + 5];
void makeSet()
{
	for (int i = 0; i <= MAX; i++)
	{
		parent[i] = i;
		ranks[i] = 0;
		d[i] = 0;
	}
}
int findSet(int u)
{
	if (parent[u] != u)
		parent[u] = findSet(parent[u]);
	return parent[u];
}
void unionSet(int u, int v)
{
	int up = findSet(u);
	int vp = findSet(v);
	if (up == vp)
		return;
	if (ranks[up] > ranks[vp])
		parent[vp] = up;
	else if (ranks[up] < ranks[vp])
		parent[up] = vp;
	else
	{
		parent[up] = vp;
		ranks[vp]++;
	}
}
int main()
{
	freopen("friends.inp", "r", stdin);
	freopen("friends.out", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n, m, max, u, v, temp;
		max = 0;
		cin >> n >> m;
		makeSet();
		for (int j = 0; j < m; j++)
		{
			cin >> u >> v;
			unionSet(u, v);
		}
		for (int j = 1; j <= n; j++)
		{
			int temp = findSet(j);
			d[temp]++;
			if (d[temp] > max)
				max = d[temp];
		}
		cout << max << endl;
	}
}