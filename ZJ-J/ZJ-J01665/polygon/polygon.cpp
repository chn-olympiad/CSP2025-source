#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5001],ans;
void dfs(int m,int C,int l)
{
	if(l==0)
	{
		if(C>2*a[m])ans=(ans+1)%998244353;
		return;
	}
	for(int i=m+1;i<=n-l+1;i++)dfs(i,C+a[i],l-1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		long long s=2;
		for(int i=1;i<=n;i++)s=(s*2)%998244353;
		s-=1+n+n*(n-1)/2;
		cout<<s;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)dfs(j,a[j],i-1);
	}
	cout<<ans;
	return 0;
}
