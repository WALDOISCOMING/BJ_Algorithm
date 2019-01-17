#include<iostream>
#include<cstdio>
using namespace std;
int tri[44];
void setTri() {
	tri[0] = 1;
	for (int i = 1; i < 44; i++) {
		tri[i] = tri[i-1] +(i+1) ;
	}
}

int canTri(int input) {
	for (int i = 0; i < 44; i++) {
		for (int j = 0; j < 44; j++) {
			for (int k = 0; k < 44; k++) {
				if (input == tri[i] + tri[j] + tri[k])
					return 1;
			}
		}
	}
	return 0;
}

int main() {
	int N = 0;
	cin >> N;
	setTri();
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		printf("%d\n",canTri(input));
	}
	return 0;
}