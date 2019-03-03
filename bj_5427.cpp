#include<iostream>
#include<queue>
#include<string>
using namespace std;
int testCase;
int w;
int h;
const int roff[4] = { -1, 1, 0, 0 };
const int coff[4] = { 0, 0, -1, 1 };
class Point {
public:
	int x;
	int y;
	Point() {};
	Point(int yy, int xx) { x = xx; y = yy; };
	~Point() {};
};
int main() {
	scanf("%d",&testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d %d",&w,&h);
		char input[1001][1001] = {0};
		int arr[1001][1001] = {0};//숫자 넣기용도
		string str;
		queue<Point> fire;
		queue<Point> queue;
		Point start;
		Point fi;
		bool check = false;
		for (int j = 0; j < h; j++) {
			cin >> str;
			for (int x = 0; x < w; x++) {				
				input[j][x] = str.at(x);
				if (input[j][x] == '@') {
					start = Point(j, x);
					queue.push(start);
					arr[j][x] = 1;
				}
				if (input[j][x] == '*') {
					fi = Point(j,x);
					fire.push(fi);
				}
			}
		}
		while (!queue.empty()) {
			int queSize = queue.size();
			for (int z = 0; z < queSize; z++) {
				Point now = queue.front();
				int nowX = now.x;
				int nowY = now.y;
				queue.pop();
				if (input[nowY][nowX] == '*')continue;

				for (int j = 0; j < 4; j++) {
					int nextY = nowY + roff[j];
					int nextX = nowX + coff[j];
					if (nextX < 0 || nextY < 0 || nextX >= w || nextY >= h ) {
						printf("%d\n", arr[nowY][nowX]);
						check = true;
						break;
					}
					if (arr[nextY][nextX] == 0 && input[nextY][nextX] == '.') {
						arr[nextY][nextX] = arr[nowY][nowX] + 1;
						now = Point(nextY, nextX);
						queue.push(now);
					}
				}
				if (check)
					break;
			}

			if (check)
				break;
			int fireSize = fire.size();
			for (int z = 0; z < fireSize; z++) {
				Point nowF = fire.front();
				fire.pop();
				int nowFX = nowF.x;
				int nowFY = nowF.y;
				for (int j = 0; j < 4; j++) {
					int nextFY = nowFY + roff[j];
					int nextFX = nowFX + coff[j];
					if (nextFX < 0 || nextFY < 0 || nextFX >= w || nextFY >= h) continue;
					if (input[nextFY][nextFX] == '.') {
						input[nextFY][nextFX] = '*';
						nowF = Point(nextFY, nextFX);
						fire.push(nowF);
					}
				}

			}
		}

		if (!check) {
			printf("IMPOSSIBLE\n");
		}


	}
}