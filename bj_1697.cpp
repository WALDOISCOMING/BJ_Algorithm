#include<iostream>
#include<queue>
using namespace std;
int main() {
	int N, K;
	scanf("%d %d",&N,&K);
	int arr[100001] = {0};
	queue<int> que;
	que.push(N);
	arr[N] = 1;
	int next = 0;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		next = now + 1;
		if (next <= 100000&&arr[next]==0) {
			arr[next] = arr[now] + 1;
			que.push(next);
			if (next == K) {
				break;
			}
		}
		next = now - 1;
		if (next >= 0&&arr[next]==0) {
			arr[next] = arr[now] + 1;
			que.push(next);
			if (next == K) {
				break;
			}
		}

		next = 2 * now;
		if (next <= 100000 && arr[next] == 0) {
			arr[next] = arr[now] + 1;
			que.push(next);
			if (next == K) {
				break;
			}
		}

	}
	printf("%d\n",arr[K]-1);

}