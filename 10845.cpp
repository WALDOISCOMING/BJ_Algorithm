#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int N;
queue<int> q;
int main() {
	cin >> N;
	string input;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "push") {
			cin >> number;
			q.push(number);
			cout << number;
		}
		else if (input == "pop") {
			if (q.size() == 0)
				cout << "-1";
			else {
				cout << q.front();
				q.pop();
			}
		} else if(input=="size") {
			cout << q.size();
		}
		else if (input == "empty") {
			cout << (q.size() == 0 ? 1 : 0);
		}
		else if (input=="front") {
			if (q.size() == 0)
				cout << "-1";
			else {
				cout << q.back();
			}

		}
		else if (input=="back") {
			if (q.size() == 0)
				cout << "-1";
			else {
				cout << q.front();
			}
		}
	}
}