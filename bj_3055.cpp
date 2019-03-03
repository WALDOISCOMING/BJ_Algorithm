#include<iostream>
#include<queue>
#include<string>
using namespace std;
int direction[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
class P {
public:
	int y;
	int x;
	P() {};
	P(int yy, int xx) { y = yy; x = xx; };
	~P() {};
};

int R,C;
int main() {
	scanf("%d %d",&R,&C);
	queue<P> S;
	queue<P> X;
	P tmp;
	P target;
	string str;
	char ch;
	char arr[51][51];
	int visit[51][51] = {0};
	for (int i = 0; i < R; i++) {
		cin >> str;
		for (int j = 0; j < C; j++) {
			ch = str.at(j);
			arr[i][j] = ch;
			if (arr[i][j] == 'D') {
				target = P(i, j);
			}
			if (arr[i][j] == 'S') {
				visit[i][j] = 1;
				tmp = P(i, j);
				S.push(tmp);
			}
			if (arr[i][j] == '*') {
				tmp = P(i, j);
				X.push(tmp);
			}
		}
	}

	bool end = false;
	while (!S.empty()) {
		int sCount = S.size();
		for (int i = 0; i < sCount; i++) {
			tmp = S.front();
			int nowY = tmp.y;
			int nowX = tmp.x;	
			S.pop();
			if (arr[nowY][nowX] == '*') { continue; }
		
			for (int j = 0; j < 4; j++) {
				int nextY = nowY + direction[j][0];
				int nextX = nowX + direction[j][1];

				if (nextY >= 0 && nextY < R&&nextX >= 0 && nextX < C &&
					(arr[nextY][nextX] == '.' || arr[nextY][nextX] == 'D') && visit[nextY][nextX] == 0) {

					visit[nextY][nextX] = visit[nowY][nowX] + 1;
					if (arr[nextY][nextX] == 'D') {
						end = true;
						break;
					}

					tmp = P(nextY, nextX);
					S.push(tmp);
				}
			}
		if (end)
			break;
		}

		int xCount = X.size();
		for (int i = 0; i < xCount; i++) {
			tmp = X.front();
			X.pop();
			int nowBY = tmp.y;
			int nowBX = tmp.x;
			for (int j = 0; j < 4; j++) {
				int nextY = nowBY + direction[j][0];
				int nextX = nowBX + direction[j][1];
				if (nextY >= 0 && nextY < R&&nextX >= 0 && nextX < C &&
					(arr[nextY][nextX] == '.')) {
					arr[nextY][nextX] = '*';
					tmp = P(nextY, nextX);
					X.push(tmp);
				}
			}
		}

	}
	if (end) {
		printf("%d\n",visit[target.y][target.x]-1);
	}
	else {
		printf("KAKTUS\n");
	}

}