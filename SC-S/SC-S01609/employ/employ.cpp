#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, m;
int lst;
int a[N];
int p;
int tong[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int len = unique(a + 1, a + 1 + n) - a - 1;
	for (int i = 1; i <= len; ++i) {
		p += min(tong[i], a[i] - lst);
		lst = a[i];
	}
	int _ans = 1;
	for (int i = m; i >= m - p + 1; -i) {
		_ans *= i;
	}
	for (int i = p; i >= 1; --i) {
		_ans /= i;
	}
	printf("%d", _ans % 998244353);
	return 0;
}