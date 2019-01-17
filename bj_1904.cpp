#include<iostream>

using namespace std;
long long arr[1000001];
int main(void) {
	int N = 0;
	cin >> N;

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] = arr[i] % 15746;
	}
	printf("%lld",arr[N]);


}