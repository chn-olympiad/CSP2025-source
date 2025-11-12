#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod = 998244353;
ll n,m;
ll c[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	bool flag = 0;
	for(ll i = 1; i <= n; i++)
	{
		if(s[i] == '0') flag = 1;
	}
	for(ll i = 1; i <= n; i++) cin >> c[i];
	if(flag == 0)
	{
		ll ans = 1;
		for(ll i = 1; i <= n; i++)
		{
			ans *= i;
			ans %= Mod;
		}
		cout << ans << "\n";
		return 0;
	}
	return 0;
}
