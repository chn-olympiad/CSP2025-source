#include <bits/stdc++.h>
using namespace std;
const int CN = 505,MOD = 998244353;
int n,m,cnt,ans,p[CN],c[CN];
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = ' '+s;
	for (int i = 1;i <= n;i++)
	{
		p[i] = i;
		cin >> c[i];
	}
	if (n <= 18)
	{
		do
		{
			cnt = 0;
			for (int i = 1;i <= n;i++)
				if (s[i] == '1' && c[p[i]] > i-1-cnt)
					cnt++;
			if (cnt >= m)
				ans++;
		}while (next_permutation(p+1,p+n+1));
		cout << ans;
		return 0;
	}
	if (m == n)
	{
		bool flag = 1;
		for (int i = 1;i <= n;i++)
			if (s[i] == '0' || !c[i])
				flag = 0;
		if (flag)
		{
			ans = 1;
			for (int i = 1;i <= n;i++)
				ans = (long long)ans*i%MOD;
			cout << ans;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
