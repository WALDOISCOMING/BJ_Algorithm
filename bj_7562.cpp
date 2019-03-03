#include<iostream>
#include<queue>
using namespace std;
int dir[8][2] = { {-1,-2},{-2,-1},{-1,2},{-2,1},{1,-2},{2,-1},{1,2},{2,1} };
class Point {
public:
	int x;
	int y;
	Point() {};
	Point(int yy, int xx) { y = yy; x = xx; }
	~Point() {};
};

int testCase;
int l;
int main() {
	scanf("%d",&testCase);
	for (int i = 0; i < testCase; i++) {
		int arr[301][301] = {0};
		scanf("%d",&l);
		int nx, ny;
		scanf("%d %d",&ny,&nx);
		int targetX, targetY;
		scanf("%d %d", &targetY, &targetX);

		if (nx == targetX&&ny == targetY) {
			printf("0\n");
			continue;
		}
		queue<Point> que;
		Point startP = Point(ny,nx);
		que.push(startP);
		Point tmp;
		while (!que.empty()) {
			tmp = que.front();
			que.pop();
			int nowX = tmp.x;
			int nowY = tmp.y;
			if (nowX == targetX&&nowY == targetY) {
				printf("%d\n",arr[targetY][targetX]);
				break;
			}
			for (int j = 0; j < 8; j++) {
				int nextY = nowY + dir[j][0];
				int nextX = nowX + dir[j][1];
				if (nextY >= 0 && nextY <l &&  nextX >= 0 && nextX  <l
					&&arr[nextY][nextX] == 0) {
					arr[nextY][nextX] = arr[nowY][nowX] + 1;
					Point next = Point(nextY, nextX);
					que.push(next);
				}
			}
		}


	}

}