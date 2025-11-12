#include <bits/stdc++.h>
using namespace std;
int a[10000];
bool b[10000];
int zhb[10000];
int n;
int start = 1;
int sum = 0;

int pd(int m) {
	int summ = 0;
	for (int j = 1; j <= m; j++) {
		summ += zhb[j];
	}
	for (int j = 1; j <= m; j++) {
		if (summ <= (zhb[j] * 2))
			return 0;
	}
	return 1;
}

void dfs(int k, int m, int start) {
	if (k == m + 1) {
		if (pd(m)) {
			sum++;
			sum = sum % 998244353;
		}

		return;
	}
	for (int i = start; i <= n; i++) {
		if (b[i] == 1)
			continue;
		zhb[k] = a[i];
		b[i] = 1;
		start = i;
		dfs(k + 1, m, start);
		zhb[k] = 0;
		b[i] = 0;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		dfs(1, i, start); //1=开始层数，i=终止层数，start避免重复
	}
	cout << sum % 998244353 ;

	return 0;
}
