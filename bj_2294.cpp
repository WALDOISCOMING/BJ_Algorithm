#include<iostream>

using namespace std;
int arr[10001];
int coin[1001];
int main() {
	int N;
	cin >> N;
	int K;
	cin >> K;
	for (int i = 0; i < N; i++)
		cin >> coin[i];
	for (int i = 0; i < 10001; i++)
		arr[i] = 1000000;
	arr[0] = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < N; j++) {
			int minBest = 1000000;
			if (i / coin[j] > 0) {
				if (i%coin[j] == 0) {
					minBest = i / coin[j];
				}
				else {
					minBest = arr[i - coin[j]] + 1;
				}
			}
			arr[i] = minBest < arr[i] ? minBest : arr[i];
		}
	}
	if (arr[K] >= 1000000)
		printf("-1");
	else
		printf("%d",arr[K] );


}