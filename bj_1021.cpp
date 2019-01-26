#include<iostream>
#include<deque>
using namespace std;
int N;
int M;
int cnt = 0;
int target[51];
deque<int> que;
int find(int num) {
	for (int i = 0; i < que.size(); i++) {
		if (num == que.at(i))
			return i;
	}
}

int main() {
	cin >> N;
	cin >> M;
	int now = 0;
	for (int i = 0; i < N; i++) {
		que.push_back(i+1);
	}
	for (int i = 0; i < M; i++) {
		cin >> target[i];
	}
	for (int i = 0; i < M; i++) {
		now = find(target[i]);
		if (now<= que.size()-now) {//앞이 더 가깝다.
			while (now!=0) {
				cnt++;
				int front = que.front();
				que.pop_front();
				que.push_back(front);
				now = find(target[i]);
			}
			que.pop_front();
		}else { // 뒤가 더 가깝다.
			while (now != 0) {
				cnt++;
				int back = que.back();
				que.pop_back();
				que.push_front(back);
				now = find(target[i]);
			}
			que.pop_front();
		}
	}
	cout << cnt;
}