#include <cstdio>
#include <stack>
#include<algorithm>
using namespace std;
int a[100001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	stack<int> s;
	long long ans = 0;
	long long i;
	for (i = 0; i<n; i++) {
		int left = i;
		while (!s.empty() && a[s.top()] > a[i]) {
			int height = a[s.top()];
			s.pop();
			int width = i;
			if (!s.empty()) {
				ans = max(ans,height*(i - s.top() - 1));
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		int height = a[s.top()];
		s.pop();
		if (!s.empty()) {
			ans = max(ans, height*(i - s.top() - 1));
		}
	}
	printf("%d\n", ans);
	return 0;
}