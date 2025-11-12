#include<bits/stdc++.h>
using namespace std;
int n,m,a[502],qzh[502];
unsigned long long ans,zt;
void dfs(int m,int p)
{

	if(m<=0)
	{
		zt=1;
		for(int i=0;i<=p;i++)
		{
			zt=zt*2;
			zt=zt%998244353;
		}
		ans+=zt;
		ans=ans%998244353;
		return;
	}
	for(int i=p;i>=0;i--)
	{
		if(qzh[i]<m)
		return;
		dfs(m-a[i],i-1);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a[0];
	qzh[0]=a[0];
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
		qzh[i]=qzh[i-1]+a[i];
	}
	
	sort(a,a+n);
	for(int i=n-1;i>=2;i--)
	{
		dfs(a[i]+1,i-1);
	}
	cout<<ans;
	return 0;
}
