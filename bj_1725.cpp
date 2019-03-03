#include <cstdio>
#include <stack>
#include<algorithm>
using namespace std;
int main() {
	unsigned long long a[100001];
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%llu",&a[i]);
	}
	unsigned long long result = 0;
	stack<int> s;
	unsigned long long top;
	unsigned long long width;
	for (int i = 0; i <= n; i++) {
		while (!s.empty()&&a[s.top()]>a[i]) {			
			top = s.top();
			s.pop();
			if (s.empty()) {
				width = i;
			}
			else {
				width = i -s.top()- 1;
			}
			result = result > width*a[top] ? result : width*a[top];
		}
		s.push(i);
	}
	printf("%llu",result);
	return 0;
}