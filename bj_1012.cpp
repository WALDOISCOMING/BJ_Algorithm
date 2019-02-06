#include<iostream>
using namespace std;
int arr[51][51];
int visit[51][51];
int M, N, K;
int testCase;
void visiting(int x,int y) {
	if (x - 1 >= 0&&!visit[x-1][y]&&arr[x-1][y]==1) {
		visit[x-1][y] = true;
		visiting(x-1,y);
	}
	if (y - 1 >= 0 && !visit[x][y-1]&& arr[x][y-1] == 1) {
		visit[x][y-1] = true;
		visiting(x, y-1);
	}
	if (x + 1 < M && !visit[x +1][y]&&arr[x + 1][y] == 1) {
		visit[x+1][y] = true;
		visiting(x + 1, y);
	}
	if (y + 1 < N && !visit[x][y+1]&&arr[x][y+1] == 1) {
		visit[x][y+1] = true;
		visiting(x, y + 1);
	}
	
}

void clean() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			arr[i][j] = 0;
			visit[i][j] = false;
		}
	}
}
int main() {
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int count = 0;
		cin >> M >> N >> K;
		clean();
		int x, y;
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (!visit[x][y]&&arr[x][y]==1) {					
					visit[x][y] = true;
					visiting(x,y);
					count++;
				}
			}
		}
		cout << count << endl;

	}
}