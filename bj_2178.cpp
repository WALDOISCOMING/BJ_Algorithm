#include<iostream>
#include<queue>
#include<string>
using namespace std;
int arr[101][101];
int visit[101][101];
int N;
int M;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x;
			scanf("%1d",&x);
			arr[i][j] = x;
			visit[i][j] = 0;
		}
	}
	queue<int> qx;
	queue<int> qy;
	qy.push(0);
	qx.push(0);
	visit[0][0] = 1;
	while (!qy.empty()) {
		int nowy = qy.front();
		int nowx = qx.front();
		qy.pop();
		qx.pop();
		if (nowy + 1 <N && arr[nowy + 1][nowx] == 1 && visit[nowy + 1][nowx] == 0) {
			visit[nowy + 1][nowx] = visit[nowy][nowx] + 1;
			qy.push(nowy + 1);
			qx.push(nowx);
		}
		if (nowy - 1 >= 0 && arr[nowy - 1][nowx] == 1 && visit[nowy - 1][nowx] == 0) {
			visit[nowy - 1][nowx] = visit[nowy][nowx] + 1;;
			qy.push(nowy - 1);
			qx.push(nowx);
		}
		if (nowx+1<M&&arr[nowy][nowx+1]==1&& visit[nowy][nowx + 1]==0) {
			visit[nowy][nowx + 1] = visit[nowy][nowx]+1;
			qy.push(nowy); 
			qx.push(nowx + 1);
		}
		if (nowx - 1 >= 0 && arr[nowy][nowx - 1] == 1 && visit[nowy][nowx - 1] == 0) {
			visit[nowy][nowx - 1] = visit[nowy][nowx] + 1;
			qy.push(nowy);
			qx.push(nowx - 1);
		}
	}
	cout << visit[N-1][M-1] << endl;
	

}