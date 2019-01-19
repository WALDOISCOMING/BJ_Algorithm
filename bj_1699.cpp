#include<iostream>
#include<math.h>
using namespace std;
int arr[100001];
int main() {
	int N;
	cin >> N;
	arr[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j*j <= i; j++) {
			if (arr[i] > arr[i - j*j] + 1 || arr[i] == 0)
				arr[i] = arr[i - j*j] + 1;
		}
	}

	printf("%d", arr[N]);
}