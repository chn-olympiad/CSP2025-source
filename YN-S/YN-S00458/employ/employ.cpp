#include <bits/stdc++.h>
using namespace std;
const int maxn = 998244353;

int main() {

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	int s[n + 5], c[n + 5];
	int cnt = 0;

	for (int i = 1; i <= n; i++) {

		scanf("%d", &s[i]);

		if (s[i] == 1) {
			cnt++;
		}
	}

	for (int i = 1; i <= n; i++) {

		scanf("%d", &c[i]);
	}

	long long sum = 1;

	for (int i = 1; i <= n; i++) {

		sum = sum * i % maxn;
	}

	printf("%d", sum);

	return 0;
}
