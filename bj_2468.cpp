#include<iostream>
int N;
int H;
int arr[101][101];
bool visit[101][101];
int ans = 0;
void dfs(int x,int y,int best) {
	if (x - 1 >= 0 && !visit[x - 1][y] && arr[x - 1][y] > best) {
		visit[x - 1][y] = true;
		dfs(x - 1, y,best);
	}

	if (y - 1 >= 0 && !visit[x][y - 1] && arr[x][y - 1]> best) {
		visit[x][y - 1] = true;
		dfs(x, y - 1,best);
	}

	if (x + 1 <N && !visit[x + 1][y] && arr[x + 1][y]> best) {
		visit[x + 1][y] = true;
		dfs(x + 1, y,best);
	}

	if (y + 1 <N && !visit[x][y + 1] && arr[x][y + 1] > best) {
		visit[x][y + 1] = true;
		dfs(x, y + 1,best);
	}
}
int main() {
	scanf("%d",&N);
	int best = 0;
	int totalBest = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d",&arr[i][j]);
			best = best > arr[i][j] ? best : arr[i][j];
		}
	}

	for (int x = 0; x <= best; x++) {
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && arr[i][j]>x) {
					visit[i][j] = true;
					ans++;
					dfs(i,j,x);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
			}
		}
		totalBest = totalBest > ans ? totalBest : ans;
	}
	printf("%d\n",totalBest);

}