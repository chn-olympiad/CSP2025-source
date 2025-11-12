#include <bits/stdc++.h>
using namespace std;
int n, m;
int sum = 0;
int  a[10000];//选出的数(序列)
bool z[10000];//标记判定
char c[10000];//答题难度
int q[10000];//原始序列

int pd(int x) {
	int num = 0;
	int ac = 0;
	for (int i = 1; i <= x; i++) {
		if (c[i] == '1' && a[i] > num)
			ac++;
		else
			num++;
	}
	if (ac >= m)
		return 1;
	else
		return 0;
}

void dfs(int k) {
	if (k  == n + 1) {
		if (pd(n)) {
			sum++;
			sum = sum % 998244353;
		}


		return;
	}
	for (int i = 1; i <= n; i++) {
		if (z[i] == 1)
			continue;
		a[k] = q[i];
		z[i] = 1;
		dfs(k + 1);
		a[k] = 0;
		z[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
	}
	dfs(1);
	cout << sum % 998244353;
	return 0;
}
