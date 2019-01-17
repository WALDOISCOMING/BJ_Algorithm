#include<cstdio>
#include<iostream>
using namespace std;
char arr[50][50];
char tmp[50][50];
int N;
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
}

int findBest() {
	int best1 = 0;
	for (int i = 0; i < N - 1; i++) {
		int count = 1;
		for (int j = 0; j < N - 1; j++) {
			if (tmp[i][j] == tmp[i][j + 1]) {
				count++;
			}   else {
				best1 = best1 > count ? best1 : count;
				count = 1;
			}
		}
		best1 = best1 > count ? best1 : count;
	}
	int best2 = 0;
	for (int i = 0; i < N - 1; i++) {
		int count = 1;
		for (int j = 0; j < N - 1; j++) {
			if (tmp[j][i] == tmp[j + 1][i]) {
			count++;
			}	else {
				best2 = best2 > count ? best2 : count;
				count = 1;
			}
		}
		best2 = best2 > count ? best2 : count;
	}
	return best1>best2 ? best1 : best2;
}

int find(int i,int j) {
	int best1 = 0;
	int best2 = 0;
	copy();
	//가로 계산부터
	char ch;
	ch = tmp[i][j];
	tmp[i][j] = tmp[i][j + 1];
	tmp[i][j + 1] = ch;
	best1 = findBest();

	copy();
	ch = tmp[j][i];
	tmp[j][i] = tmp[j+1][i];
	tmp[j+1][i] = ch;
	best2 = findBest();	
	return best1>best2?best1:best2;
}
int main(void) {
	N=0;
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int best = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			int now = find(i, j);
			best = best > now ? best : now;
		}
	}
	printf("%d",best);
	return 0;
}