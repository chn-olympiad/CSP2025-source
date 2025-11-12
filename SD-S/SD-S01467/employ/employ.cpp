#include <bits/stdc++.h>
using namespace std;

// 不要紧张 暴力全打满就行

typedef long long ll;
typedef pair <ll, ll> PII;
const ll N = 5e2 + 10;
const ll INF = 1e10;
const ll P = 998244353;
ll n, m, s[N], c[N], fac[N];

ll qpow(ll a, ll p)
{
	ll ans = 1;
	while (p)
	{
		if (p & 1) ans = ans * a % P;
		a = a * a % P;
		p >>= 1;
	}

	return ans;
}

void init()
{
	fac[0] = 1;
	for (ll i = 1; i <= n; i ++) fac[i] = (fac[i - 1] * i) % P;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) {
		char c;
		cin >> c;
		s[i] = c - '0';
	}
	ll cnt = 0;
	for (ll i = 1; i <= n; i ++) {
		cin >> c[i];
		if (!c[i]) cnt ++;
	}
	init();
	
	// A
	ll res = fac[n] * qpow(fac[cnt], P - 2) % P;
	
	cout << res << endl;
	return 0;
}

