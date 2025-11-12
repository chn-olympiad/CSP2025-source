#include <bits/stdc++.h>
using namespace std;
long long n, m, s1, s2 = 0, a[10000], b[1000], v[1000];
string s;

void dfs(int x) {
	if (x == n + 1) {
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1) {
			continue;
		}
		a[x] = i;
		v[i] = 1;
		if (x == n) {
			s1 = 0;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == '0') {
					s1++;
				} else if (s1 >= b[a[j + 1]]) {
					s1++;
				}
			}
			if (n - s1 >= m) {
				s2++;
				s2 = s2 % 998, 244, 353;
			}
		}
		dfs(x + 1);
		v[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	if (n == m) {
		cout << 0;
		return 0;
	} else {
		dfs(1);
		cout << s2;
	}
	return 0;
}
