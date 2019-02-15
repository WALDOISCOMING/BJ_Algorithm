#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int M;
int N;
int K;
int ans;
vector<int> v;
bool visit[101][101];
int map[101][101];
void dfs(int x,int y) {

	if (x-1>=0&&!visit[x-1][y]&&map[x-1][y]==0) {
		ans++;
		visit[x - 1][y] = true;
		dfs(x-1,y);
	}

	if (y - 1 >= 0 && !visit[x][y-1] && map[x][y-1] == 0) {
		ans++;
		visit[x][y-1] = true;
		dfs(x, y-1);
	}

	if (x +1 <M && !visit[x + 1][y] && map[x + 1][y] == 0) {
		ans++;
		visit[x + 1][y] = true;
		dfs(x + 1, y);
	}

	if (y+1 <N && !visit[x][y+1] && map[x][y+1] == 0) {
		ans++;
		visit[x][y+1] = true;
		dfs(x, y+1);
	}

}
int main() {
	scanf("%d %d %d",&M,&N,&K);
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visit[i][j] = false;
			map[i][j] = 0;
		}
	}
	int LX;
	int LY;
	int HX;
	int HY;
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d",&LX,&LY,&HX,&HY);
		for (int y = LY; y < HY; y++) {
			for (int x = LX; x < HX; x++) {
				map[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && map[i][j] == 0) {
				ans = 1;
				visit[i][j] = true;
				dfs(i,j);
				v.push_back(ans);
			}
		}
	}
	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d",v.at(i));
		if (i != v.size() - 1)
			printf(" ");
	}

}