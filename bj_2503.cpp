#include<iostream>
#include<string>
using namespace std;

int main() {

	bool number[1000];
	for (int i = 123; i <= 999; i++) {
		string str = to_string(i);
		if (!((str[0]==str[1]||str[1]==str[2]||str[0]==str[2]) 
			|| (str[0]-'0'==0||str[1] - '0' == 0 ||str[2] - '0' == 0))) {
			number[i] = true;
		}
	}

	int N;
	cin >> N;
	int input;
	int strike;
	int ball;
	string str_input;
	string str_i;
	for (int i = 0; i < N; i++) {		
		cin >> input >> strike >> ball;
		for (int j = 123; j <= 999; j++) {
			if (number[j]) {
				int j_strike = 0;
				int j_ball = 0;
				str_input = to_string(input);
				str_i = to_string(j);
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (x == y&&str_input[x] == str_i[y])
							j_strike++;
						if (x != y&&str_input[x] == str_i[y])
							j_ball++;
					}
				}
				if (strike != j_strike || ball != j_ball)
					number[j] = false;
			}
		}
	}

	int count = 0;
	for (int i = 123; i <= 999; i++) {
		if (number[i])
			count++;
	}
	printf("%d",count);
	return 0;
}