#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int arr[9];
	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);

	int total = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6] + arr[7] + arr[8];
	int exc1, exc2;
	sort(arr, arr + 9);
	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if (total - arr[i] - arr[j] == 100) {
				exc1 = i; exc2 = j;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i == exc1 || i == exc2)continue;
			printf("%d\n", arr[i]);
	}
	return 0;
}