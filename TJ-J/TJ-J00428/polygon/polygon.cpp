#include<bits/stdc++.h>
using namespace std;
long long dp[5005][5005],a[5005],ans; 
int n,m,num; 
int cie[25];
bool vis[25];
void ff(int tgt,int now,int bg)
{
	if(tgt==now)
	{
		int sum=0,mx=0;
		for(int i=0;i<tgt;i++)
		{
			sum+=cie[i];
			mx=max(mx,cie[i]);
		}
		if(2*mx<sum)
		{
			ans++;
			if(ans>=998244353)ans-=998244353;
		}
		return ;
	}
	for(int i=bg;i<=n;i++)
	{
		if(vis[i])continue;
		cie[now]=a[i];
		vis[i]=1;
		ff(tgt,now+1,i+1);
		vis[i]=0;
		
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		if(num>m)m=num;
		a[i]=num;
	}
	if(m==1)
	{
		
		for(int i=3;i<=n;i++)
		{long long tms=1,dvd=1;
			for(int j=n;j>n-i;j--)
			{
				tms*=j;
				dvd*=n-j+1;
				if(tms>998244353)
				{
					tms/=dvd;
					dvd=1;
				}
			}ans+=tms/dvd;ans%=998244353;
		}
		cout<<ans;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			ff(i,0,1);
		}
		cout<<ans;
	}
	return 0;
}
