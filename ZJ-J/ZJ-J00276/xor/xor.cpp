#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, m, ans, x;
map <int, int> mp, emp;
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	mp[0]++;
	scanf("%lld%lld", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &m);
		x ^= m;
		if(mp[x ^ k])
		{
			ans++;
			mp = emp;
		}
		mp[x]++;
	}
	cout << ans;
}
