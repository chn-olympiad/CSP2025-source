#include <bits/stdc++.h>
#define LL long long
#define DB double
#define ST string

#define fr(x, y, z) for(int x = (y); x <= (z); x ++ )
#define dfr(x, y, z) for(int x = (y); x >= (z); x -- )

using namespace std;

const int N = 5e5 + 10;
int n, f[N];
LL a[N], Xsum[N], k;
unordered_map <LL, int> mp;

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	fr(i, 1, n) cin >> a[i];
	fr(i, 1, n) Xsum[i] = Xsum[i - 1] ^ a[i];
	
	mp[0] = 0;
	fr(i, 1, n)
	{
		f[i] = f[i - 1];
		if(mp.count(Xsum[i] ^ k))
		{
//			cout << i << " lst:" << f[mp[Xsum[i] ^ k]] << '\n';
			f[i] = max(f[i], f[mp[Xsum[i] ^ k]] + 1);
		}
		mp[Xsum[i]] = i;
	}
	
	cout << f[n] << '\n';
	
	return 0;
}

