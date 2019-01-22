#include<iostream>
#define MOD 10007;
using namespace std;

int arr[1001][1001];
int main() {
	int N;
	int K;
	cin >> N >> K;
	
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j])%MOD;
		}
	}
	int result = arr[N][K] % MOD;
	printf("%d", result);	
}