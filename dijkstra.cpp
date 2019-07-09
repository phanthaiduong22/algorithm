#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100	
const int INF = 1e9;
vector<vector<pair<int, int>>>graph;
vector<int>dist(MAX, INF);
int path[MAX];
struct option
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
	{
		return a.second > b.second;
	}
};
void Dijkstra(int s)
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, option>pq;
	pq.push(make_pair(s, 0));
	dist[s] = 0;
	while (!pq.empty())
	{
		pair<int, int>top = pq.top();
		pq.pop();
		int u = top.first;
		int w = top.second;
		for (int i = 0; i < graph[u].size(); ++i)
		{
			pair<int, int>neighbor = graph[u][i];
			if (w + neighbor.second < dist[neighbor.first])
			{
				dist[neighbor.first] = w + neighbor.second;
				pq.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
				path[neighbor.first] = u;
			}
		}
	}
}

int main()
{
	int n, s, t;
	dist = vector<int>(MAX, INF);
	cin >> n;
	s = 0; t = 4;
	graph = vector<vector<pair<int, int>>>(MAX + 5, vector<pair<int, int>>());
	int d = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> d;
			if (d > 0)
				graph[i].push_back(pair<int, int>(j, d));
		}
	Dijkstra(s);
	int ans = dist[t];
	cout << ans;
	return 0;
}