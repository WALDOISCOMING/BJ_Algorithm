#include<iostream>
using namespace std;

int N;
int M;
int K;
int trash[1001][1001];
bool visit[1001][1001];
int input[10001][2];
int ans = 0;
int dfs(int x, int y) {
	if (x-1>=1&&!visit[x-1][y]&&trash[x-1][y]==1) {
		visit[x-1][y] = true;
		ans++;
		dfs(x - 1, y);
	}
	if (y - 1 >= 1 && !visit[x][y-1] && trash[x][y-1] == 1) {
		visit[x][y - 1] = true;
		ans++;
		dfs(x, y - 1);
	}
	if (x + 1 <= N && !visit[x + 1][y] && trash[x + 1][y] == 1) {
		visit[x+1][y] = true;
		ans++;
		dfs(x + 1, y);
	}
	if (y+1 <= M && !visit[x][y+1] && trash[x][y+1] == 1) {
		visit[x][ y + 1] = true;
		ans++;
		dfs(x, y + 1);
	}
	return 0;
}
int main() {
	cin >> N >> M >> K;
	int x, y;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			trash[i][j] = 0;
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		input[i][0] = y;
		input[i][1] = x;
		trash[y][x] = 1;
	}
	int best = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visit[i][j] && trash[i][j] == 1) {
				ans = 1;
				visit[i][j] = true;
				dfs(i, j);
				best = best > ans ? best : ans;
			}
		}
	}

	cout << best;


}