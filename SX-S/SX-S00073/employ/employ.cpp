#include <bits/stdc++.h>
using namespace std;
long long n,m,s[510],b[510],sx[510],v[510],rans;
const long long mo=998244353;
string ss;
void dfs(long long x)
{
	if(x==n+1)
	{
		long long loser=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(loser>=b[sx[i]])
			{
				loser++;
			}
			else
			{
				if(s[i]==1)
				{
					ans++;
				}
				else
				{
					loser++;
				}
			}
		}
		if(ans>=m)
		{
			rans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			sx[x]=i;
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>ss;
	for(int i=1;i<=n;i++)
	{
		s[i]=ss[i-1]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	dfs(1);
	printf("%lld",rans);
	return 0;
}