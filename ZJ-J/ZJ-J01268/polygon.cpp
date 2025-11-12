#include<bits/stdc++.h>
using namespace std;
long long n,a[5010];
long long sum;
bool f(long long i,long long l,long long m)
{
	if(l>2*a[i]&&m>=3)	
		return true;
	return false;
}
void dfs(long long i,long long l,long long ans,long long m)
{
	if(i>n)
	{
		sum=sum+ans;
		sum=sum%998244353;
		return;
	}
	if(ans==998244353)ans=0;
	if(f(i+1,l+a[i+1],m+1))
	{
		dfs(i+1,l+a[i],ans+1,m+1);
		i--;
		l=l-a[i+1];
		m--;
		if(ans)ans--;
	}
	dfs(i+1,l+a[i],ans,m+1);
	dfs(i+1,l,ans,m);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<sum%998244353;
	return 0;
}
