#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long ans;
int n;
void dfs(int x,int ma,int num,int ge)
{
	if(x==n+1)
	{
		if(ge>=3&&num>ma*2)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	int k=max(ma,a[x]);
	dfs(x+1,k,num+a[x],ge+1);
	dfs(x+1,ma,num,ge);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>a[3]*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[n]==1)
	{
		ans=0;
		for(int i=4;i<=n;i++)
		{
			long long as=1;
			for(int j=n;j>n-i;j--)
			{
				as*=j;
				as%=998244353;
			}
			for(int j=1;j<=i;j++)
			{
				as/=j;
				as%=998244353;
			}
			
			ans+=as;
			ans%=998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	if(n<=26)
	{
		dfs(1,0,0,0);
		cout<<ans%998244353;
		return 0;
	}
	return 0;
}
