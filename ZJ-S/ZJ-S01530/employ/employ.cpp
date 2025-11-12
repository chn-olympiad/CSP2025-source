#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long ans,n,m,num = 1,c[505],sum[505],minn = 1e9,fl;
string s;
bool flag,flagg,hav[505];
vector<int> g;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	//s = " " + s;
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
		if (c[i] != 0)
			fl++;
		/*if (!vis[c[i]])
		{
			g.push_back(c[i]);
			sum[c[i]]++;
			minn = max(1,min(c[i],minn));
		}*/
	}
	for (int i = 0;i < n;i++)
	{
		if (s[i] == '0')
		{
			num++;	
		}
	}
	//bufenfen
	if (fl < m)
	{
		cout << 0;
		return 0;
	}
	else if (num == n)
	{
		cout << 0;
		return 0;
	}
	else if (num == 0)//?
	{
		ans = 1;
		for (int i = 1;i <= n;i++)
		{
			ans = ans * 1ll * i % mod;
		}
		cout << ans;
		return 0;
	}
	sort (c + 1,c + n + 1);
	if (m == 1)//?
	{
		ans = 0;
		long long x = n - fl + 1,xx = n - fl + 1;
		for (int i = 0;i <= n - fl;i++)
		{
			long long x = n - fl + 1,cnt = 1,anss = 1;
			while (c[x] <= i && x <= n)
				x++;
			if (x > n)
				break;
			for (int j = 1;j <= n - i - 1;j++)
				cnt = cnt * 1ll * j % mod;
			anss = cnt;
			cnt = 1;
			for (int j = 1;j <= i;j++)
				cnt = cnt * 1ll * j % mod;
			anss = anss * cnt % mod;
			anss = anss * (n - x + 1) % mod;
			ans = (ans + anss) % mod;
			cout << ans << endl;
			
		}
		cout << ans % mod;
		return 0;
	}
	else if (m == n)
	{
		ans = 1;
		for (int i = 1;i <= n;i++)
		{
			ans = ans * i % mod;
		}
		cout << ans;
		return 0;
	}
	//buhuizuo
	/*while (c[num] == 0)
	{
		num++;
	}
	for (int i = 0;i < s;i++)
	{
		for (int j = minn;j <= n;j++)
		{
			if (sum[j] && j <= tot)
				
		}
	}*/
	cout << ans;
	return 0;
}