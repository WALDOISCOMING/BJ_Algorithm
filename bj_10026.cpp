#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<int> v;
bool visit_2[101][101];
bool visit_1[101][101];
char color[101][101];
int N;
int ans_1;
int ans_2;
void dfs_1(int x,int y,char c) {
	if (x - 1 >= 0 && !visit_1[x - 1][y] && color[x - 1][y] == c) {
		visit_1[x - 1][y] = true;
		dfs_1(x - 1, y,c);
	}

	if (y - 1 >= 0 && !visit_1[x][y - 1] && color[x][y - 1] == c) {
		visit_1[x][y - 1] = true;
		dfs_1(x, y - 1,c);
	}

	if (x + 1 <N && !visit_1[x + 1][y] && color[x + 1][y] == c) {
		visit_1[x + 1][y] = true;
		dfs_1(x + 1, y,c);
	}

	if (y + 1 <N && !visit_1[x][y + 1] && color[x][y + 1] == c) {
		visit_1[x][y + 1] = true;
		dfs_1(x, y + 1,c);
	}
}
bool isBlue(char c) {
	return c == 'B' ? true : false;
}
void dfs_2(int x, int y, int c) {
	if (x - 1 >= 0 && !visit_2[x - 1][y] 
		&& ((isBlue(c)&&isBlue(color[x-1][y]))|| (!isBlue(c) && !isBlue(color[x - 1][y])))) {
		visit_2[x - 1][y] = true;
		dfs_2(x - 1, y, c);
	}

	if (y - 1 >= 0 && !visit_2[x][y - 1]
		&& ((isBlue(c) && isBlue(color[x][y-1])) || (!isBlue(c) && !isBlue(color[x][y-1])))) {
		visit_2[x][y - 1] = true;
		dfs_2(x, y - 1, c);
	}

	if (x + 1 <N && !visit_2[x + 1][y]
		&& ((isBlue(c) && isBlue(color[x + 1][y])) || (!isBlue(c) && !isBlue(color[x + 1][y])))) {
		visit_2[x + 1][y] = true;
		dfs_2(x + 1, y, c);
	}

	if (y + 1 <N && !visit_2[x][y + 1]
		&& ((isBlue(c) && isBlue(color[x][y+1])) || (!isBlue(c) && !isBlue(color[x][y+1])))) {
		visit_2[x][y + 1] = true;
		dfs_2(x, y + 1, c);
	}




}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			color[i][j] = s.at(j);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (i==0) {
					if (!visit_1[x][y]) {
						ans_1++;
						visit_1[x][y] = true;
						dfs_1(x,y,color[x][y]);
					}
				}
				else {
					if (!visit_2[x][y]) {
						ans_2++;
						visit_2[x][y] = true;
						dfs_2(x, y, color[x][y]);
					}
				}
			}
		}
	}
	cout << ans_1 << " " << ans_2<<endl;

}