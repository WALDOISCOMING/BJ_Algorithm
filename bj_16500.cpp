#include<iostream>
#include<string>
#include<vector>
using namespace std;
string input;
string arr[101];
vector<int> v[101];
bool valid[101][101];
int N;
bool check = false;

int find(int index) {
	for (int i = 0; i < v[index].size(); i++) {
		int pop = v[index].at(i);
		if (input.substr(index, arr[pop].size()) == arr[pop]) {
			if (index + arr[pop].size() == input.size()) {
				cout << "1";
				check = true;
				return 1;
			}
			else {
				find(index + arr[pop].size());
			}
		}
	}
	if (!check) {
		cout << "0";
		check = true;
	}
	return 0;
}
int main() {
	cin >> input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < N; j++) {
			if (input[i] == arr[j][0]) {
				v[i].push_back(j);
			}
		}
	}
	find(0);
	return 0;
}