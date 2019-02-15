#include<iostream>

int N;
int arr[101][101];
bool visit[101];

void dfs(int x) {
	for (int i = 0; i < N; i++) {
		if (!visit[i]&&arr[x][i]==1) {
			visit[i] = true;
			arr[x][i] = 1;
			dfs(i);
		}
	}
}
int main() {
	scanf("%d",&N);
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visit[i] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		dfs(i);
		for (int x = 0; x < N; x++) {
			if (visit[x])
				arr[i][x] = 1;
			}
		for (int x = 0; x < 101; x++) {
				visit[x] = false;
		}			
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j != N - 1) {
				printf("%d ", arr[i][j]);
			}
			else {
				printf("%d", arr[i][j]);
			}
		}
		printf("\n");
	}

}