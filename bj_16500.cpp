#include<iostream>
#include<string>
using namespace std;
string arr[101];
bool valid[101][101];
string input;
	int N;
bool find(int index) {
	for (int i = 0; i < N; i++) {
		if (valid[index][i]) {
					printf("%d\n",i);
			//실제 맞는지 비교 후 그러면 재호출 시키자.
			if (input.substr(index,index+arr[i].length()-1)==arr[i]) { 
				if (input.length()==index+ arr[i].length()) {
					return true;
				} else {
				find(index+arr[i].length()-1);
				}				
			}
		}
	}
	return false;
}

int main() {
	cin >> input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < N; j++) {
			if (input[i] == arr[j][i])
				valid[i][j] = true;
		}
	}
	cout << find(0);


	return 0;
}