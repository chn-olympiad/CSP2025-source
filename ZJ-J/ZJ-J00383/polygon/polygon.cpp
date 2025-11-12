#include<bits/stdc++.h>
using namespace std;
long long a[5005],mod=998244353,n,cnt1,c=1;
bool b[5005];
void dfs(long long cnt,long long sum,long long ma)
{
	if(cnt>n+1)
	{
		return ;
	}
	if(cnt>3)
	{
		if(sum>ma*2)
		{
			cnt1++;
			cnt%=mod;
		}
	}
	for(int i=c;i<=n;i++)
	{
		if(!b[i])
		{
		c=i;
		b[i]=true;
		dfs(cnt+1,sum+a[i],max(ma,a[i]));
		b[i]=false;
	    }
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool dd=true;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			dd=false;
		}
	}
	if(dd)
	{
		cout<<n-2;
		return 0;
	}
	dfs(1,0,0);
	cout<<cnt1;
	return 0;
}
