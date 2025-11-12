#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); \
cin.tie(0); \
cout.tie(0);
#define mod 998244353
ll n, a[5005], ans;
map <string, bool> q;
void fr() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
}
string to_strig(ll x) {
	ll p = x;
	string s = "";
	while(p) {
		s = char(p % 10 + '0') + s;
		p /= 10;
	}
	return s;
}
void dfs(ll x, ll len, ll maxn, string sum) {
	if (len > 2 * maxn && sum.size() / 2 >= 3) {
		string as = to_strig(len) + "+" + to_strig(maxn) + "+" + sum;
		if (!q[as]) {
			q[as] = 1;
		//	cout << as << "\n";
			ans = (ans + 1) % mod;
		//	cout << len << " " << maxn << " " << sum << "\n";
		}
	}
	if (x == n + 1) {
		return ;
	} 
	dfs(x + 1, len + a[x], (maxn > a[x] ? maxn : a[x]), sum + char(',') + char(x + '0'));
	//use 
	dfs(x + 1, len, maxn, sum);
	//buse
}
bool qq = 1;
int main() {
	fr();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			qq = 0;
		}
	}
	if (qq) {
		ans = 0;
		for (int i = n - 2; i >= 1; i--) {
			ll pe = 1;
			for (int j = n; j >= i; j--) {
				pe = (pe % mod) * (j % mod) % mod;
			}
			ans = (ans % mod + pe % mod) % mod;
		}
		cout << ans;
		return 0;
	}
	dfs(1, 0, 0, "");
	cout << ans % mod;
	return 0;
}

