#include<iostream>
#include<queue>
using namespace std;

int N;
int T;
int G;
bool arr[100000];
long long fun(long long value) {
	if (value>=10000) {
		value = value - 10000;
	}
	else if (value>=1000) {
		value = value - 1000;
	}
	else if (value>=100) {
		value = value - 100;
	}
	else if (value>=10) {
		value = value - 10;
	}
	else if (value>0) {
		value--;
	}
	return value;
}
int main() {
	cin >>N>> T >> G;
	arr[N] = 1;
	queue<pair<int,int>>que;
	que.push({ N,0 });
	long long now;
	long long next;
	if (N==G) {
		cout << "0";
		return 0;
	}
	while (!que.empty()) {
		now = que.front().first;
		int cnt = que.front().second;
		que.pop();
		if(cnt>T) {
			cout << "ANG";
			return 0;
		}
		if (now == G) {
			cout<<  cnt;
			return 0;
		}
		next = now + 1;
		if (next>=0&&next<=99999&&!arr[next]) {
			arr[next] = false;
			que.push({next,cnt+1});
		}

		if (!(now * 2 <= 99999)) continue;
		next = fun(now*2);
		if (next >= 0 && next <= 99999&&!arr[next]) {
			arr[next] = true;
			que.push({ next ,cnt+1});
		}
	}
	
	printf("ANG\n");
	

}