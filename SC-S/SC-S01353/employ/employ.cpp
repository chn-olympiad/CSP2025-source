#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 500 + 2, mod = 998244353;
ll n, m, a[N];
char c[N];
bool back[N];
bool is_ch[N];
ll ch[N], ans;
void dfs(ll x) {
	if (x > n) {
		memset(back, 0, sizeof back);
		ll man = 0;
		for (ll i = 1; i <= n; i++) {
			ll sum = 0;
			for (ll j = 1; j < i; j++)sum += back[ch[j]];
			if (sum >= a[ch[i]]) {
				back[ch[i]] = 1;
			} else {
				if (c[i] == '0') {
					back[ch[i]] = 1;
				} else {
					man++;
				}
			}

		}
		if (man >= m) {
			ans++;
		}
		ans %= mod;
		return;
	}
	for (ll i = 1; i <= n; i++) {
		if (is_ch[i]) continue;
		is_ch[i] = 1;
		ch[x] = i;
		dfs(x + 1);
		ch[x] = 0;
		is_ch[i] = 0;
	}
	return;
}
ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
	return f*x;
}
bool is_A = 1;
int main() {
	//freopen("employ.in", "r", stdin);
	//freopen("employ.out", "w", stdout);
	freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

	n = read(), m = read();

	cin >> (c + 1);
	for (ll i = 1; i <= n; i++) {
		if (c[i] == '0') {
			is_A = 0;
		}
	}

	for (ll i = 1; i <= n; i++) {
		a[i] = read();
	}
	if (is_A) {
		ll shi = 0;
		for (ll i = 1; i <= n; i++) if (a[i] == 0) shi++;
		if(n-shi<m){
			cout<<0;
			return 0;
		}
		ll tot = 1;
		for (ll i = n; i >= 1; i--){
			 tot *= i; tot %= mod;
		}
		cout << tot;
		return 0;
	}
	if (n == m) {
		ll num = 0;
		for (ll i = 1; i <= n; i++) num += (1 - (c[i] - '0'));
		if (num) cout << 0;
		else {
			ll shi = 0;
			for (ll i = 1; i <= n; i++) if (a[i] == 0) shi++;
			ll tot = 1;
			for (ll i = n; i >= 1; i--) tot *= i, tot %= mod;
			cout << tot;
		}
		return 0;
	}
	dfs(1);
	cout << ans % mod;
	return 0;
}