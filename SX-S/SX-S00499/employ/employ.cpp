#include <bits/stdc++.h>
//#define ll long long
using namespace std;
char a[114514];
int b[114514];
int n, m;
//priority_queue<int>
long long anss;
int M = 998244353;
bool v[114514];

void dfs(int k, int kai, int ri) {
	if (ri == m) {
		anss++;
		return;
	}
	if (k > n) {
		return;
	}
	if (m > n - kai)
		return;
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1)
			continue;
		v[i] = 1;
		if (kai >= b[i]) {
			dfs(k + 1, kai + 1, ri);
		} else {
			if (a[k] == '1')
				dfs(k + 1, kai, ri + 1);
			else
				dfs(k + 1, kai + 1, ri);
		}
		v[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> a + 1;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	dfs(1, 0, 0);
	cout << anss;
	return 0;
}
