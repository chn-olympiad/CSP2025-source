#include <bits/stdc++.h>
#define _loopc(i, a, b) for(int i = (a); i <= (b); i ++)
#define _loopo(i, a, b) for(int i = (a); i <  (b); i ++)
#define _rloopc(i, a, b) for(int i = (a); i >= (b); i --)
#define _rloopo(i, a, b) for(int i = (a); i >  (b); i --)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
	
	ll n, m; cin >> n >> m;
	ll ans = 1;
	for(ll i = 1; i <= n; i ++)
		(ans *= 1ll * i) %= 1ll * 998244353;
	
	cout << ans;
	return 0;
}