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
		if (index + arr[pop].size() == input.size()) {
			cout << "1" << endl;
			check = true;
			return 1;
		}
		else {
			find(index + arr[pop].size());
		}
	}
	if (!check) {
		cout << "0"<<endl;
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
				if (input.length()>= j + arr[i].size() && input.substr(j, arr[i].size()) == arr[i]) {
					v[i].push_back(j);
				}
			}
		}
	}
	find(0);
	return 0;
}