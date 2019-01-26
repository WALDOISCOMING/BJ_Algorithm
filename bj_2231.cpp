#include <iostream>
#include<string>
using namespace std;
int N;
string str;
int sum(int num) {
	int result = 0;
	result = num;
	str = to_string(num);
	for (int i = 0; i < str.length(); i++) {
		result = result + str.at(i) - '0';
	}
	return result;
}
int main()
{
	cin >> N;
	int out = 0;
	for (int i = 1; i <= 1000000; i++) {
		if (N == sum(i)) {
			out = i;
			break;
		}
	}
	cout << out << endl;
}