#include<iostream>
using namespace std;
char chess_input1[8][8] = { 
	{'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'},
	{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' },{ 'B','W','B','W','B','W','B','W' }
};
char chess_input2[8][8] = {
	{ 'B','W','B','W','B','W','B','W' }, { 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' }, { 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' }, { 'W','B','W','B','W','B','W','B' },
	{ 'B','W','B','W','B','W','B','W' },{ 'W','B','W','B','W','B','W','B' }
};
char input[50][50];
int compare(int x,int y) {
	int returnValue1 = 0;
	int returnValue2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess_input1[i][j] != input[i+x][j+y])
				returnValue1++;
			if (chess_input2[i][j] != input[i + x][j + y])
				returnValue2++;
		}
	}
	return returnValue1>returnValue2?returnValue2:returnValue1;
}
int main() {
	int M,N;
	cin >>M>> N;
	for (int i = 0; i < M; i++) {
		cin >> input[i];
	}
	int count = 1000;
	for (int i = 0; i <= M - 8; i++) {
		for (int j = 0; j <= N - 8; j++) {
			int r = compare(i,j);
			count = count > r ? r : count;
		}
	}
	
	printf("%d",count==1000?0:count);
	return 0;
}