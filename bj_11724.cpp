#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> v[1001];
bool isVisited[1001];

void dfs(int index) {
	isVisited[index] = true;
	for (int i = 0; i < v[index].size(); i++) {
		int n = v[index][i];
		if (!isVisited[n]) {
			dfs(n);
		}
	}

}

int main() {
	cin >> N >> M;
	int count = 0;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		if (!isVisited[i]) {
			dfs(i);
			count++;
		}
	}
	cout << count;

}