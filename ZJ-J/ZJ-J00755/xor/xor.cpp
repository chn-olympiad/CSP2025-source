#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int ans, n, k, a[N], sum = 0;
map<int, bool> mp;

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++)
	{
		mp[sum] = 1;
		sum ^= a[i];
		if(mp[sum ^ k])
		{
			ans ++;
			sum = 0;
			mp.clear();
		}
	}
	cout << ans << '\n';
	return 0;
}

