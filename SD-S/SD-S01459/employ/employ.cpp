#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 510, MOD = 998244353;
ll n, m, c[MAXN], res = 1;
string str;
void solve1() {
	ll tmp = n;
	res = 1;
	for(ll i = tmp; i >= 1; i--)
		(res *= i) %= MOD;
	cout << res;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> str;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	solve1();
	return 0;
}

