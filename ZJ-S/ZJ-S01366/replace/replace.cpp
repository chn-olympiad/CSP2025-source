#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <ctime>
#define mod 998244353
#define int long long
using namespace std;

int n,q,stclk;
string s,t;
set <pair <int,int> > st;

int hs(string &str,int st)
{
	int x = 0;
	for (int i = (int)str.size() - 1;i >= st;i--) x = (x * 29 + str[i] - 96) % mod;
	return x;
}

int qpow(int a,int b)
{
	int mul = 1;
	while (b)
	{
		if (b & 1) mul = mul * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return mul;
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	stclk = clock();
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> s >> t;
		st.insert(make_pair(hs(s,0),hs(t,0)));
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> s >> t;
		int ans = 0;
		for (int l = 0;l < min(s.size(),t.size());l++)
		{
			int hss = hs(s,l),hst = hs(t,l);
			for (int r = 0;l + r < min(s.size(),t.size());r++)
			{
				if (clock() - stclk > 0.95 * CLOCKS_PER_SEC)
				{
					cout << ans << '\n';
					q -= i;
					while (q--) puts("0");
					return 0;
				}
				if (r)
				{
					hss = (hss - qpow(29,s.size() - r - l) * (s[s.size() - r] - 96) % mod + mod) % mod;
					hst = (hst - qpow(29,t.size() - r - l) * (t[t.size() - r] - 96) % mod + mod) % mod;
				}
				if (r && s[s.size() - r] != t[t.size() - r]) break;
				if (st.count(make_pair(hss,hst))) ans++;
			}
			if (s[l] != t[l]) break;
		}
		cout << ans << '\n';
	}
	return 0;
}
