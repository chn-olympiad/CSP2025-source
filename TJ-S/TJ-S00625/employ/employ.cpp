#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m,c[505],ps[505],fct[505],cps;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<n;i++) if(s[i]-'0') ps[++cps]=i;
	fct[0]=1;
	for(int i=1;i<=n;i++) fct[i]=(i*fct[i-1])%mod;
	if(cps<m)
	{
		cout<<0;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(!c[i])
			{
				cout<<0;
				return 0;
			}
		}
		cout<<fct[n];
		return 0;
	}
	if(cps==n)
	{
		cout<<fct[n];
		return 0;
	}
	return 0;
}
