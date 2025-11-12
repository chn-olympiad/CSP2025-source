#include <bits/stdc++.h>
#define NOI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
int n, m;
int a[105];

int main() {
	NOI("seat");
	scanf("%d%d", &n, &m);
	int sum = n * m;
	for (int i = 1; i <= sum; i++) {
		scanf("%d", &a[i]);
	}
	int wdf = a[1];
	sort(a + 1, a + sum + 1, greater<int>());
	bool flag = false;
	int cnt = 0;
	for (int j = 1; j <= m; j++) {
		flag = !flag;
		if (flag) {
			for (int i = 1; i <= n; i++) {
				cnt++;
				if (a[cnt] == wdf) {
					printf("%d %d", j, i);
					return 0;
				}
			}
		} else {

			for (int i = n; i >= 1; i--) {
				cnt++;
				if (a[cnt] == wdf) {
					printf("%d %d", j, i);
					return 0;
				}
			}
		}

	}
	return 0;
}
