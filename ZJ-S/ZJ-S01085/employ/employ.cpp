#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

long long n,m,t[1000],c[1000],mod = 998244353,c0,c0_;


int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		char ch;
		cin >> ch;
		t[i] = ch-'0';
		if(t[i] == 0) c0 ++;
	}
	for(int i = 1;i <= n;i ++)
	{
		cin >> c[i];
		if(c[i] == 0) c0_ ++;
	}
	if(c0 > 0 || c0_ > 0) cout << 0;
	else
	{
		int ans = 0;
		for(int i = 1;i <= n;i ++)
		{
			ans = (ans*i)%mod;
		}
		cout << ans;
	}
	return 0;
}
