#include<iostream>

using namespace std;
int main() {
	long long arr[1001];
	int N;
	cin >> N;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + 2 * arr[i - 2];
		arr[i] = arr[i] % 10007;
	}
	printf("%d",arr[N]);
}