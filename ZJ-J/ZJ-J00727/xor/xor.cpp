#include<bits/stdc++.h>
using namespace std;
long long a[500010],ans,n,k;
void dfs(long long l,long long r,long long sum)
{
	if(l<1||r>n)
		return;
	if(sum==k)
	{
		ans++;
		return;
	}
	for(long long i=r+1;i<=n;i++)
	{
		if(sum^a[i]<=k&&a[i]!=0)
			dfs(l,i,sum^a[i]);
	}
	for(long long i=l-1;i>=1;i--)
	{
		if(sum^a[i]<=k&&a[i]!=0)
			dfs(i,r,sum^a[i]);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long x=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
			x++;
	}
	if(k==0)
	{
		cout<<x;
		return 0;
	}	
	dfs(1,1,0);	
	cout<<ans+1;
	return 0;
}
	