#include <iostream>
#include <queue>
using namespace std;
int n = 7;

void DFS(int u) {
	int A[7][7] = {
		{0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,1,0,0,1,0,0},
		{0,1,0,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	};
	static int visited[7] = { 0 };
	if (visited[u]==0) {
		cout << u << " ";
		visited[u] = 1;
		for (int v = 1; v < n; v++) {
			if (A[u][v] == 1 && visited[v] == 0) {
				DFS(v);
			}
		}
	}
}

void BFS(int i) {
	int A[7][7] = {
		{0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,1,0,0,1,0,0},
		{0,1,0,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	};
	queue<int> q;
	int u;
	cout << i << " ";
	int visited[7] = { 0 };
	visited[i] = 1;
	q.push(i);
	while (!q.empty()) {
		u = q.back();
		q.pop();
		for (int v = 1; v < n; v++) {
			if (A[u][v] == 1 && visited[v] == 0) {
				cout << v << " ";
				visited[v] = 1;
				q.push(v);
			}
		}

	}

}

int main() {
	BFS(1);
}