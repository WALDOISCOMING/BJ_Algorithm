#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
bool arr[236197];// 최대수는 236196이나 1더 크게해야지 0을 넣을수 있음.
int d, p;
int mod(int number) {
	int returnValue = 0;

	for (int i = number; i > 0; i = i / 10) {
		int pow = 1;
		for (int j = 0; j < p; j++) {
			pow = pow* (i % 10);
		}
		returnValue += pow;
		//returnValue += pow(i%10,p);
	}
	return returnValue;
}
int main(void) {
	scanf("%d %d",&d,&p);
	vector<int> v;
	while (true) {
		if (arr[d] == true) {
			break;
		}
		arr[d] = true;
		v.push_back(d);
		d = mod(d);
	}
	for (int i = 0; i < v.size(); i++) {
		if (d == v.at(i)) {
			printf("%d",i);
			break;
		}
	}
	return 0;
}