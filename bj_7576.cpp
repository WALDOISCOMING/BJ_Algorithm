#include<iostream>
#include<queue>
using namespace std;
int M;
int N;
int dir[4][2] = {
	{ 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 }
};
class Point {
public:
	int x;
	int y;
	Point() {};
	Point(int yy, int xx) { y = yy; x = xx; };
	~Point() {};
};

int arr[1001][1001];
bool checkZero() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0)
				return true;
		}
	}
	return false;
}
int findBest() {
	int best = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			best = arr[i][j] > best ? arr[i][j] : best;
		}
	}
	return best;
}
int main() {
	scanf("%d %d",&M,&N);
	queue<Point> queue;
	Point tmp;
	int input = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {		
			scanf("%d",&input);
			if (input == 1) {
				tmp = Point(i,j);
				queue.push(tmp);
			}
			arr[i][j] = input;
		}
	}
	if (!checkZero()) {
		printf("0\n");//하나도 없으면.
		return 0;
	}

	//que method 실행.

	while (!queue.empty()) {
		tmp = queue.front();
		queue.pop();
		int nowX = tmp.x;
		int nowY = tmp.y;
		for (int j = 0; j < 4; j++) {
			int nextY = nowY + dir[j][0];
			int nextX = nowX + dir[j][1];
			if (nextY >= 0 && nextY <N &&  nextX >= 0 && nextX  <M
				&&arr[nextY][nextX] == 0) {
				arr[nextY][nextX] = arr[nowY][nowX] + 1;
				Point next = Point(nextY, nextX);
				queue.push(next);
			}
		}
	}
	if (!checkZero()) {
		printf("%d\n",findBest()-1);//하나도 없으면.
	}
	else {
		printf("-1\n");
	}



}