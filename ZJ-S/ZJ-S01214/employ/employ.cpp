#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
const long long mod=998244353;
int x[N],n,m,rp,sum[N],p[N];
long long ans=1;
string str;
void fre()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int main()
{
	fre();
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		cin>>x[i];
		rp+=(x[i]!=0);
	}
	if(n<=18)
	{
		bool ok=1;
		ans=0;
		while(ok)
		{
			ok=next_permutation(p+1,p+n+1);
			int pp=0,sum=0;
			for(int i=1;i<=n;i++)
			{
				if(sum<x[p[i]]&&str[i-1]=='1')pp++;
				if(sum>=x[p[i]]||str[i-1]=='0')sum++;
			}
			if(pp>=m)ans++;
		}
		cout<<ans<<'\n';
	}
	else
	{
		if(rp<m)cout<<0<<'\n';
		else
		{
			for(int i=1;i<=n;i++)
			ans=ans*(n-i+1)%mod;
			cout<<ans<<'\n';
		}
	}
}

