#include<iostream>
#include<queue>
using namespace std;

int arr[1000001] = { 0 };
int main() {
	queue<int> que;
	int F,S,G,U,D;
	scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
	que.push(S);
	arr[S] = 1;
	if (S==G) {
		printf("0\n");
		return 0;
	}
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		if (now == G)
			break;
		if (now+U<=F&&arr[now+U]==0) {
			arr[now + U] = arr[now] + 1;
			que.push(now+U);
		}
		if (now -D>=0&&arr[now-D] == 0) {
			arr[now -D] = arr[now] + 1;
			que.push(now - D);
		}
	}
	if (arr[G]==0) {
		printf("use the stairs\n");
	}
	else {
		printf("%d\n",arr[G]-1);
	}


}