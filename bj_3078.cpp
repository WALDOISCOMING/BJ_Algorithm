#include<iostream>
#include<deque>
#include<string>
using namespace std;
int N;
int K;
long cnt = 0;
long save[300001];
deque<int> que[21];
string str;

void find(int index) {
	int bf = 0;
	while (que[index].size()>1) {
		for (int i = 1+ bf; i < que[index].size(); i++) {
			if (que[index].at(i) - que[index].front() <= K) {
				cnt++;
			}
			else {
				bf = i-1;//pop 시켜줄 것 이므로 -1 해주자.
				cnt += save[i - 1];
				que[index].pop_front();
				break;
			}
		}
			que[index].pop_front();
	}
}

int main() {
	cin >> N >> K;
	save[0] = 0;
	for (int i = 1; i <= 300000; i++) {
		save[i] = save[i - 1] + i;
	}
	for (int i = 0; i < N; i++) {
		cin >> str;
		que[str.size()].push_back(i);
	}
	for (int i = 2; i <= 20; i++) {
		find(i);
	}

	cout << cnt;
}