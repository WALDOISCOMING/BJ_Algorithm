#include<iostream>
#include<queue>
using namespace std;
int L, R, C;
class Point {
public:
	int x;
	int y;
	int z;
	Point() {};
	Point(int zz, int yy, int xx) { x = xx; y = yy; z = zz; };
	~Point(){}
};
Point startP;
Point endP;
int main() {
	cin >> L >> R >> C;
	while (!(L==0&&R==0&&C==0)) {
		char floors[31][31][31] = {0};
		int visit[31][31][31] = { 0 };
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					char ch;
					cin >> ch;
					if (ch == 'S') {
						visit[i][j][k] = 0;
						startP = Point(i,j,k);
					}
					if (ch == 'E') {
						endP = Point(i,j,k);
					}
					floors[i][j][k] = ch;
				}
			}
		}
		queue<Point> que;
		que.push(startP);

		while(!que.empty()) {
			Point p = que.front();
			que.pop();
			int x = p.x;
			int y = p.y;
			int z = p.z;
			if (x+1<C&&visit[z][y][x+1]==0&&(floors[z][y][x+1]=='.'|| floors[z][y][x + 1] == 'E')) {
				que.push(Point(z,y,x+1));
				visit[z][y][x+1] = visit[z][y][x] + 1;
			}
			if (x -1>=0&&visit[z][y][x-1] == 0 && (floors[z][y][x-1] == '.' || floors[z][y][x - 1] == 'E')) {
				que.push(Point(z, y, x-1));
				visit[z][y][x-1] = visit[z][y][x] + 1;
			}

			if (y + 1<R&&visit[z][y+1][x] == 0 && (floors[z][y+1][x] == '.' || floors[z][y+1][x] == 'E')) {
				que.push(Point(z, y+1, x));
				visit[z][y+1][x] = visit[z][y][x] + 1;
			}
			if (y -1>=0&&visit[z][y - 1][x] == 0 && (floors[z][y-1][x] == '.' || floors[z][y-1][x] == 'E')) {
				que.push(Point(z, y - 1, x));
				visit[z][y - 1][x] = visit[z][y][x] + 1;
			}

			if (z + 1<L&&visit[z+1][y][x] == 0 && (floors[z+1][y][x] == '.' || floors[z+1][y][x] == 'E')) {
				que.push(Point(z+1, y, x));
				visit[z+1][y][x] = visit[z][y][x] + 1;
			}
			if (z -1>=0&&visit[z - 1][y][x] == 0 && (floors[z - 1][y][x] == '.' || floors[z - 1][y][x] == 'E')) {
				que.push(Point(z - 1, y, x));
				visit[z - 1][y][x] = visit[z][y][x] + 1;
			}

		}
		int x = endP.x;
		int y = endP.y;
		int z = endP.z;
		int result = visit[z][y][x];
		if (result == 0) {
			cout << "Trapped!" << endl;
		}
		else {
			cout << "Escaped in " <<result << " minute(s)." << endl;
		}
		cin >> L >> R >> C;
	}
}