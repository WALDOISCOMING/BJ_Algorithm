#include <iostream>
using namespace std;

int main() {
	int n, m;
	int print[101], print_tmp[101], print_add;
	int chk[101], chk_tmp[101], chk_add;
	int testcase;

	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> print[i];
			chk[i] = 0;
		}
		chk[m] = 1;

		for (int i = 0; i < n; i++) {
			int max = print[i];
			int max_add = i;
			print_add = 0;
			chk_add = 0;
			for (int j = i; j < n; j++) {
				if (max < print[j]) {
					max = print[j];
					max_add = j;
				}
			}
			for (int j = max_add; j < n; j++) {
				print_tmp[print_add++] = print[j];
				chk_tmp[chk_add++] = chk[j];
			}
			for (int j = i; j < max_add; j++) {
				print_tmp[print_add++] = print[j];
				chk_tmp[chk_add++] = chk[j];
			}

			print_add = 0;
			chk_add = 0;
			for (int j = i; j < n; j++) {
				print[j] = print_tmp[print_add++];
				chk[j] = chk_tmp[chk_add++];
			}
		}

		for (int i = 0; i < n; i++) {
			if (chk[i] == 1) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}
