#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int input;
	cin >> input;
	while (input--) {
		int a, b;
		scanf("%d,%d",&a,&b);
		printf("%d\n",a+b);
	}
	return 0;
}