#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 510;
const int mod = 998244353;
int n, m;
char s[MAXN];
int a[MAXN];
int ans = 1;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++)
		ans = (ans * i) % mod;
	cout << ans;
	return 0;
}