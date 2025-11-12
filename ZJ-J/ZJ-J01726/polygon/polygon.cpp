#include<bits/stdc++.h>
using namespace std;
int n,l[5005],maxl,ans=0;
int choose[5001];
int C(int m,int n)
{
	int tmpm=1,tmpn=1;
	for(int i=n;i>=n-m+1;i--) tmpn*=i;
	for(int i=1;i<=m;i++) tmpm*=i;
	return tmpn/tmpm;
}
void dfs(int n,int k,int dp,int lastx)
{
	if(dp==k+1)
	{
		int sum=0;
		for(int i=1;i<=k;i++)
		{
			sum+=choose[i];
		}
		if(sum>maxl) 
		{
			ans++;
		}
		return ;
	}
	for(int i=lastx+1;i<=n;i++)
	{
		choose[dp]=l[i];
		dfs(n,k,dp+1,i);
		choose[dp]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i];
	sort(l+1,l+n+1);
	if(l[n]==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=C(i,n);
		}
	}
	else if(n<=3)
	{
		if(l[1]+l[2]>l[3]) cout<<1;
		else cout<<0;	
	}
	else
	{
		for(int k=3;k<=n;k++)
		{
			maxl=l[k];
			for(int i=2;i<k;i++) dfs(k,i,1,0);
		}
	}
	cout<<ans%998244353;
	return 0;
}
