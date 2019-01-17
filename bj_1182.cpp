#include<iostream>
using namespace std;
int N;
int sum;
int counting = 0;
int arr[21];

void f_sum(int prev, int index) {
	printf("prev:%d,index:%d\n",prev,index);
	if (index == N) {
		if (prev == sum) {
			counting++;
		}
		return;
	}

	f_sum(prev+arr[index],index+1);
	f_sum(prev, index + 1);

}

int main() {
	cin >> N >> sum;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	f_sum(0,0);
	if (sum == 0) counting--;
	printf("%d", counting);
}