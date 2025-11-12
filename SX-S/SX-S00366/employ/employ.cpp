#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int h[510];
int jp[510];
int a[510];
int w;

void dfs(int t) {
	if (t == n) {
		int o = 0;
		int k = 0;
		for (int i = 0; i < s.size(); i++) {
			if (a[i] > o) {
				if (s[i] == '0') {
					o++;
				} else {
					k++;
				}
			} else {
				o++;
			}
		}
		if (k >= m) {
			w++;
			w %= 998244353;
		}
	}
	for (int i = 0; i < n; i++) {
		if (jp[i] == 0) {
			jp[i] = 1;
			a[t] = h[i];
			dfs(t + 1);
			jp[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	sort(h, h + n);
	dfs(0);
	cout << w;
}