#include<iostream>

int cnt = 0;
bool visit[100001];
bool finish[100001];
int target[100001];
int testCase;
int N;
void dfs(int i) {
	visit[i] = true;
	int next = target[i];

	if (!visit[next]) {
		dfs(next);
	}
	else if (!finish[next]) {
		for (int j = next; j != i; j = target[j]) {
			cnt++;
		}
		cnt++;
	}
	finish[i] = true;

}
int main() {
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d",&N);
		cnt = 0;
		for (int j = 1; j <= N; j++) {
			scanf("%d",&target[j]);
		}
		for (int j = 1; j <= N; j++) {
			if (!visit[j]) {
				dfs(j);
			}
		}
		for (int j = 1; j <= N; j++) {
			finish[j] = false;
			visit[j] = false;
		}
		printf("%d\n",N-cnt);

	}
}
