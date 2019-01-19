#include<iostream>

int input[2][100011];
int result[2][100011];
using namespace std;
int best(int a,int b) {
	return a > b ? a : b;
}
int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i<testCase; i++) {
		int N;
		scanf("%d",&N);
		for (int j = 0; j<2; j++) {
			for (int x = 2; x<N+2; x++)
				scanf("%d", &input[j][x]);
		}
		if (N == 1) {
			printf("%d\n", best(input[0][2],input[1][2]));
		}
		else if (N == 2) {
			printf("%d\n", best(best(best(input[0][2], input[1][2]),input[0][3]),input[1][3]));
		}
		else {
			for (int j = 2; j<N+2; j++) {
				result[0][j] = best(best(result[0][j-1],result[1][j-1]+input[0][j]),result[1][j-2]+input[0][j]);
				result[1][j] = best(best(result[1][j - 1], result[0][j - 1] + input[1][j]), result[0][j - 2] + input[1][j]);

			}
			printf("%d\n", result[0][N+1]>result[1][N+1] ? result[0][N+1] : result[1][N+1]);
		}

	}
	return 0;
}