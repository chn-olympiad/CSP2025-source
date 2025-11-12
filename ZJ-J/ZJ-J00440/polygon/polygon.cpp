#include<bits/stdc++.h>
using namespace std;

int a[5001], n;
bool b[5001];

inline int dfs(int p) {
	if (p < 3)
		return 0;
	p--;
	int t = 0;
	for (int i = n - p; i <= n; i++) {
		if (!b[i]) {
			b[i] = true;
			t += dfs(p);
			b[i] = false;
		}
	}
	int sum = 0, m = 0;
	for (int i = 1; i <= n; i++) {
		if (!b[i]) {
			sum += a[i];
			m = max(m, a[i]);
		}
	}
	if(sum > m * 2)
		return t + 1;
	return 0;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	memset(b, false, sizeof(b));
	for (int i = 1; i<= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", dfs(n));
	return 0;
}
