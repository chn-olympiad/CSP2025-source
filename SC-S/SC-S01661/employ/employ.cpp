#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505, M = 998244353;
int n, m;
bool a[N];
int c[N], now[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string str;
	cin >> str;
	for (int i = 1; i <= n; i++)a[i] = str[i - 1] == '1';
	for (int i = 1; i <= n; i++)cin >> c[i];
	for (int i = 1; i <= n; i++)now[i] = i;
	if(n <= 20) {
		int ans = 0;
		do {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if(cnt >= c[now[i]] || !a[i])cnt ++;
			}
			if(n - cnt >= m) {
//				cout << cnt << ' ';
//				for (int i = 1; i <= n; i++)cout << now[i] << ' ';
//				puts("");
				ans ++;
			}
		}while(next_permutation(now + 1, now + n + 1));
		cout << ans;
		return 0;
	}
	bool s = 1;
	for (int i = 1; i <= n; i++)s |= a[i];
	if(s) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)if(c[i])cnt ++;
		if(cnt >= m) {
			ll ans = 1;
			for (int i = 1; i <= n; i++) {
				ans *= i;
				ans %= M;
			}
			cout << ans;
		} else {
			printf("0");
			return 0;
		}
	}
	return 0;
}