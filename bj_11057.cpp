#include<iostream>

#define MODE 10007;
using namespace std;

int arr[1001][10] = {};

int up(int i,int j) {
	int sum = 0;
	for (int x = j; x <= 9; x++) {
		sum = (sum + arr[i][x])%MODE;
	}
	return sum;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i <= 9; i++)
		arr[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			arr[i][j] = up(i-1,j)%MODE;
		}
	}
	int sum = 0;
	for(int i=0;i<=9;i++)
		sum = (sum + arr[N][i]) % MODE;
	printf("%d",sum);
}