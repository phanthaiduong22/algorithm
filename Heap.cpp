#include <queue>

using namespace std;

int main()
{
	priority_queue<int>pq;//max-heap
	priority_queue<int, vector<int>, greater<int>>pq1;//min-heap
	priority_queue<int, vector<int>, greater<int>>pq2;//min-heap
	int value = pq.top();
	pq.push(3);
	pq.pop();
	pq.size();
	pq.empty();
	pq1.swap(pq2);
	pq.push(3);
	pq = priority_queue<int>();//clear dung phuong phap gan cho mot priority queue moi
}