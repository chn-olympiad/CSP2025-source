#include <bits/stdc++.h>

using namespace std;

const int N = 11, P = 998244353;

int n, m, c[N], p[N], ans;
char s[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s + 1;
	if(n <= 10) {
		for (int i = 1; i <= n; ++i) cin >> c[i];
		for (int i = 1; i <= n; ++i) p[i] = i;
		do {
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if(cnt < c[p[i]] && s[i] == '1') ;
				else ++cnt;
			}
			if(n - cnt >= m) ++ans, ans %= P;
		} while(next_permutation(p + 1, p + 1 + n));
		cout << ans % P;	
	}
	else {
		ans = 1;
		for (int i = 1; i <= n; ++i) ans = ans * i % P;
		cout << ans;
	}
	return 0;
}
