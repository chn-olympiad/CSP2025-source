#include <bits/stdc++.h>
#define ll long long
#define f_1(i,a,b) for(ll i=a;i<=b;i++)
#define f_0(i,a,b) for(ll i=a;i>=b;i--)
using namespace std;
ll n, m, c[1000], ans = 1;
const ll mod = 998244353;
string l;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> l;
	f_1(i, 1, n) cin >> c[i];
	f_1(i, 1, n) ans = (ans *i) % mod;
	cout << ans;
	return 0;
}