#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<int> v;
int ans = 0;
int home[26][26];
bool visit[26][26];
void dfs(int x, int y) {
	if (x - 1 >= 0 && !visit[x - 1][y] && home[x - 1][y] == 1) {
		visit[x - 1][y] = true;
		ans++;
		dfs(x - 1, y);
	}
	if (y - 1 >= 0 && !visit[x][y - 1] && home[x][y - 1] == 1) {
		visit[x][y - 1] = true;
		ans++;
		dfs(x, y - 1);
	}
	if (x + 1 < N && !visit[x + 1][y] && home[x + 1][y] == 1) {
		visit[x + 1][y] = true;
		ans++;
		dfs(x + 1, y);
	}
	if (y + 1 < N && !visit[x][y + 1] && home[x][y + 1] == 1) {
		visit[x][y + 1] = true;
		ans++;
		dfs(x, y + 1);
	}
}
int main() {
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
			home[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			home[i][j] = s.at(j)-'0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]&&home[i][j] == 1) {
				ans = 1;
				visit[i][j] = true;
				dfs(i,j);
				v.push_back(ans);
			}
		}
	}
	sort(v.begin(),v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}