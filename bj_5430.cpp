#include<iostream>
#include<vector>
#include<string>
#include <cstring>
using namespace std;
int main() {
	int testCase;
	vector<int> num_arr;
	int N;
	char arr[400005], func_p[100005];
	scanf("%d",&testCase);
	while(testCase--) {
		num_arr.clear();
		scanf("%s %d %s", &func_p, &N, &arr);
		char * tmp = strtok(arr, "[,]");
		while (tmp) {
			num_arr.push_back(stoi(tmp));
			tmp = strtok(NULL, "[,]");
		}
		int point = 0, start = 0, end = N;
		bool normal = true;
		for (int i = 0; func_p[i]; i++) {

			if (start == end && func_p[i] == 'D') {
				normal = false;
				break;
			}

			switch (func_p[i]) {
			case 'R':
				point = point == start ? end : start;
				break;
			case 'D':
				point = point == start ? ++start : --end;
				break;
			}

		}

		if (!normal) {
			printf("error\n");
		}
		else {
			printf("[");
			if (point == start && start != end) {
				for (int j = start; j < end - 1; j++)
					printf("%d,", num_arr[j]);
				printf("%d", num_arr[end - 1]);
			}
			else if (start != end) {
				for (int j = end - 1; j > start; j--)
					printf("%d,", num_arr[j]);
				printf("%d", num_arr[start]);
			}
			printf("]\n");
		}
	}
	return 0;
}