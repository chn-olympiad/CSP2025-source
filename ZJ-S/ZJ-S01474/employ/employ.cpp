#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
int c[505];
int fd[505];
bool vis[505];
long long cnpp = 0;
void dfs(int x) {
	if (x == n + 1) {
		long long cnt = 0;
		long long lyts = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '0' || lyts >= c[fd[i]]) {
				lyts++;
			} else if (s[i - 1] == '1') {
				cnt++;
			}
		}
		/*
		18 5
		110111101111001101
		6 0 4 2 1 2 5 4 3 3 4 2 6 3 4 5 6 2

		*/
		if (cnt >= m)
			cnpp++;
		cnpp %= 998244353;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			fd[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(1);
	cout << cnpp;
	return 0;
}