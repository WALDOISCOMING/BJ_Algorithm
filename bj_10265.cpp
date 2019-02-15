#include<iostream>

int N;
int K;
int best = 0;
int arr[1001];
bool visit[1001];
bool finish[1001];
int cnt = 0;
void dfs(int i) {
	visit[i] = true;
	int next = arr[i];
	if (!visit[next]) {
		dfs(next);
	}
	else if (!finish[next]) {
		for (int j = next; j != i; j = arr[j])
			cnt++;
		cnt++;
	}
	finish[i] = true;
}

int main() {
	scanf("%d %d",&N,&K);
	for (int i = 1; i <= N; i++) {
		scanf("%d",&arr[i]);
	}
	if (N==K) {
		printf("%d\n",N);
	}
	else {
		best = 0;
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				cnt = 0;
				dfs(i);
				if (cnt <= K) {
					best = best > cnt ? best : cnt;
				}
				for (int j = 1; j <= N; j++)
					finish[j] = false;
			}
		}
		printf("%d",best);
	}

}