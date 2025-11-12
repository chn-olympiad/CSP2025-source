#include <bits/extc++.h>
#define int long long
using namespace std;

int T = 1;
constexpr int MAXN = 514,MOD = 998244353;
int n,m,c[MAXN],p[MAXN];
string s;
inline void Solve()
{
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	bool flg = 1;
	for(int i = 1;i <= n;i++)
		cin >> c[i],p[i] = i,flg &= (s[i] == '1');
	if(flg)
	{
		int ans = 1,cnt = n;
		for(int i = 1;i <= n;i++)
			ans = ans * i % MOD,cnt -= (c[i] == 0);
		cout << ((cnt >= m) ? ans : 0);
		return ;
	}
	int ans = 0;
	do
	{
		int num = 0;
		for(int i = 1;i <= n;i++)
		{
			if((i - 1 - num >= c[p[i]]) || (s[i] == '0'))
				continue;
			++num;
		}
		ans += (num >= m);
	}
	while(next_permutation(p + 1,p + n + 1));
	cout << ans % MOD;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef LOCAL
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	while(T--)
		Solve();
}