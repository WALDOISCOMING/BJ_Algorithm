#include<iostream>
#include<queue>
#include <string.h>
using namespace std;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
class P {
public:
	int x;
	int y;
	int can;
	P() {};
	P(int yy, int xx, int b) { y = yy; x = xx; can = b; };
	~P() {};
};
int M;
int N;
int arr[1001][1001];
int visit[1001][1001][2];

queue<P> que;
P tmp;

int f_que() {
	while (!que.empty()) {
		tmp = que.front();
		int nowX = tmp.x;
		int nowY = tmp.y;
		int can = tmp.can;
		que.pop(); 
		if (nowY == M - 1 && nowX == N - 1) {
			return visit[nowY][nowX][can];
		}
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dir[i][0];
			int nextY = nowY + dir[i][1];
			if (nextX >= 0 && nextY >= 0 && nextY < M&&nextX < N) {
				//벽 뚫고 상황 바꿀때ㅣ 아직 안뚫어불때만 가능함.
				if (arr[nextY][nextX] == 1 && can) {
					visit[nextY][nextX][can - 1] = visit[nowY][nowX][can] + 1;
					tmp = P(nextY, nextX, can - 1);
					que.push(tmp);
				}
				else if (arr[nextY][nextX] == 0 && visit[nextY][nextX][can] == 0) {
					visit[nextY][nextX][can] = visit[nowY][nowX][can] + 1;
					tmp = P(nextY, nextX, can);
					que.push(tmp);
				}
			}
		}
	}
	return -1;
}

int main() {

	scanf("%d %d",&M,&N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d",&arr[i][j]);
		}
	}
	tmp = P(0,0,1);
	visit[0][0][1] = 1;
	que.push(tmp);
	printf("%d\n", f_que());
	return 0;
}