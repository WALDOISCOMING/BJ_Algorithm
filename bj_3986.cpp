#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		stack<char> st;
		for (int j = 0; j < str.length(); j++) {
			if (st.size()!=0&&str.at(j)==st.top()) {//이전 내용 혹은, 이전에 존재하던 값들 중 최상단과 비교.
				st.pop();
			}
			else {
				st.push(str.at(j));
			}
		}
		if (st.size() == 0)
			count++;
	}

	cout << count;
}