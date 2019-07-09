//complexity: O(V^3)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 105
#define INF 1e9
vector<vector<int>>graph;
vector<vector<int>>dist;
vector<vector<int>>path;
int V;
void printPath(int s, int t)
{
	int b[MAX];
	int m = 0;
	while (s != t)
	{
		b[m++] = t;
		t = path[s][t];
	}
	b[m++] = s;
	for (int i = m - 1; i >= 0; i--)
		cout << b[i] << " ";
}
bool FloyWarshall(vector<vector<int>>& graph, vector<vector<int>>& dist)
{
	for(int i=0;i<V;i++)
		for (int j = 0; j < V; j++)
		{
			dist[i][j] = graph[i][j];
			if (graph[i][j] != INF && i != j)
			{
				path[i][j] = i;
			}
			else
			{
				path[i][j] = -1;
			}
		}
	for(int k=0;k<V;k++)
		for(int i=0;i<V;i++)
			for (int j = 0; j < V; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
	for (int i = 0; i < V; i++)
		if (dist[i][i] < 0)
			return false;
	return true;
}
int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int temp;
	cin >> V;
	graph = vector<vector<int>>(V, vector<int>(V));
	dist = vector<vector<int>>(V, vector<int>(V));
	path = vector<vector<int>>(V, vector<int>(V));
	for(int i=0;i<V;i++)
		for (int j = 0; j < V; j++)
		{
			cin >> temp;
			if (temp == 0 && i != j)
				graph[i][j] = INF;
			else
				graph[i][j] = temp;
		}
	FloyWarshall(graph, dist);
	int s = 0;
	int t = 4;
	int result = dist[s][t];
	printPath(s, t);
	cout << result;
	return 0;
}