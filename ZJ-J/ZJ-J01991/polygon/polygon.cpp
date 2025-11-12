#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long ans=0;
int a[5010];
bool flag=true;
void dfs(int deep,int sum,int maxn)
{
	if(deep==n+1)
	{
		if(sum>maxn*2)
		{
			ans++;
		} 
		return ;
	}
	dfs(deep+1,sum,maxn);
	dfs(deep+1,sum+a[deep],max(maxn,a[deep]));
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flag=false;
		}
	}
	if(!flag)
	{
		dfs(1,0,0);
	}
	if(flag)
	{
		for(int i=3;i<=n;i++)
		{
			unsigned long long sum=1,desum=1;
			for(int j=n-i+1;j<=n;j++)
			{
				sum=sum*j/(j-n+i)%998244353;
			}
			ans=(ans+sum)%998244353;
		}
	}
	cout<<ans%998244353;
	return 0;
}
