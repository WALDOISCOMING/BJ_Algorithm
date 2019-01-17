#include<iostream>

using namespace std;
int com(int x, int y) {
	return x > y ? y : x;
}
	int arr[1000001];
int main(void) {
	int X;
	cin >> X;
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= X; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0) arr[i] = com(arr[i], arr[i / 3] + 1);
		if (i % 2 == 0) arr[i] = com(arr[i], arr[i / 2] + 1);
	}
	printf("%d", arr[X]);
	return 0;
}