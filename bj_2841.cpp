#include<iostream>
#include<stack>
using namespace std;

int main() {
	int N;
	int P;
	int IN;
	int IP;
	stack<int> st[7];
	scanf("%d %d",&N,&P);
	int count = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &IN, &IP);
		if (st[IN].size()==0) {
			count++;
			st[IN].push(IP);
			continue;
		}
		while (st[IN].top() > IP) {
			count++;
			st[IN].pop();
			if (st[IN].size() == 0)break;
		}
		if (st[IN].size() != 0 && st[IN].top() == IP) continue; 
			count++;
			st[IN].push(IP);
		
	}
	printf("%d\n",count);

}