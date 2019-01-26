#include<iostream>
#include<deque>
#include<string>
using namespace std;
int N;
int K;
long cnt = 0;
deque<int> que[21];
string str;

void find(int index) {
	while (que[index].size()>1) {
		for (int i = 1; i < que[index].size(); i++) {
			if (que[index].at(i) - que[index].front() <= K) {
				cnt++;
			}
			else {
				que[index].pop_front();
				break;
			}
		}
			que[index].pop_front();
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> str;
		que[str.size()].push_back(i);
	}
	for (int i = 1; i <= 20; i++) {
		find(i);
	}

	cout << cnt;
}