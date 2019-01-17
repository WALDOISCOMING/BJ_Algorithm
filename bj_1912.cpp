#include<iostream>
#include<cstdio>
using namespace std;

long long best(long long a, long long b) {
	return a > b ? a : b;
}
int input[100001];
long long tmp[100001];
int main()
{
	int count;
	cin >> count;
	long long result = 0;
	for (int i = 0; i < count; i++) {
		scanf("%d",&input[i]);
	}
	tmp[0] = input[0];
	result = tmp[0];

	for (int i = 0; i < count - 1; i++) {
		tmp[i + 1] = best(input[i + 1],tmp[i]+input[i+1]);
		result = best(result, tmp[i + 1]);
	}
	cout << result;
	return 0;

}