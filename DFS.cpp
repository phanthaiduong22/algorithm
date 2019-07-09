#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAX 100
int V, E;
bool visited[MAX];
int path[MAX];
vector<int>graph[MAX];

void DFS(int src)
{
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		path[i] = -1;
	}
	stack<int>s;
	visited[src] = true;
	s.push(src);
	while (!s.empty())
	{
		int u = s.top();
		s.pop();
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				s.push(v);
				path[v] = u;
			}
		}
	}
}
void printPathRecursion(int s, int f)
{
	if (s == f)
		cout << f << " ";
	else
	{
		if (path[f] == -1)
			cout << "No Path" << endl;
		else
		{
			printPathRecursion(s, path[f]);
			cout << f << " ";
		}
	}
}
int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int u, v;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int s = 0;
	int f = 5;
	DFS(s);
	printPathRecursion(s, f);
	return 0;
}