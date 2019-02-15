#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int arr[1001][1001];
int N;
int M;
int V;
bool dvisit[1001];
bool bvisit[1001];

void dfs(int index) {
	dvisit[index] = true;
	cout << index<<" ";	
	for (int i = 1; i <= N; i++) {
		if (!dvisit[i] && arr[index][i]) {
			dfs(i);
		}
	}
}

void bfs(int index) {
	queue<int> q;
	q.push(index);
	bvisit[index] = true;
	while (!q.empty()) {
		index = q.front();
		cout << index << " ";
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!bvisit[i]&&arr[index][i]==1) {
				q.push(i);
				bvisit[i] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	int x, y;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(V);
	cout << endl;
	bfs(V);




}