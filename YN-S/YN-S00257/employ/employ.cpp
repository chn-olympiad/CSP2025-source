#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int mod = 998244353;
int n, m, a[N], b, ans, tot;
string s;

void dfs() {
	int t = 0;
	for (int i = 0; i < n; i++) {
		t++;
		ans = 0;
		for (int j = t; j < n + t; j++) {
			if (b > a[j]) {
				b++;
				continue;
			} else {
				if (s[j] - '0' == 0)
					b++;
				else
					ans++;
			}
		}
		if (ans > m)
			tot++;
		if (t == n)
			break;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n; i < n * n; i++)
		a[i] = a[i - 3], s[i] = s[i - 3];
	dfs();
	cout << tot % 998244353;
	return 0;
}