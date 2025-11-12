#include<bits/stdc++.h>
using namespace std;
string x;
long long n,i,l,h,k,m,p,t,Max,a[505050],f[5005][5005],j,s;
void dfs(long long x,long long s,long long Max)
{
	if(x==n+1)
	{
		if(s>Max*2)
		{
			h=(h+1)%998244353;
			return ;
		}
		else return ;
	}
	dfs(x+1,s+a[x],max(Max,a[x]));
	dfs(x+1,s,Max);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	p=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)p=1;
	}
	if(!p)
	{
		f[1][1]=1;
		for(i=2;i<=n+1;i++)
		{
			for(l=1;l<=i;l++)
			{
				f[i][l]=(f[i-1][l]+f[i-1][l-1])%998244353;
			}
		}
		for(i=3;i<=n;i++)
		{
			h=(h+f[n+1][i+1])%998244353;
		}
		cout<<h;
	}
	else
	{
		dfs(1,0,0);
		cout<<h;
	}
	return 0;
}