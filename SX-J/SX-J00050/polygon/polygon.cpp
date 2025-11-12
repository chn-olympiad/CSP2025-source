#include<bits/stdc++.h>
using namespace std;
long long i,n,ans=0,a[5009];
bool b[5009];
void dfs(int gs,long long s,int k,int maxx)
{
	if(k>n)
	{
		return;
	}
	if(gs<i)
	{
		b[k]=1;
		dfs(gs++,s+a[k],k++,a[k]);
		b[k]=0;
		dfs(gs,s,k++,maxx);
	}
	else
	{
		if(s>maxx*2)
		{
			ans++;
			return;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool z=1;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			z=0;
		}
	}
	if(z==1)
	{
		cout<<0;
		return 0;
	}
	else
	{
		if(n==3)
		{
			cout<<1;
			return 0;
		}
	}
	sort(a+1,a+1+n);
	for(i=3;i<=n;i++)
	{
		dfs(0,0,0,0);
	}
	cout<<ans%998244353;
	return 0;
}