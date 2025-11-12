#include<bits/stdc++.h>
using namespace std;
long long a[500010],ans,n;
void dfs(long long l,long long r,long long sum,long long m)
{
	if(l<1||r>n)
		return;
	if(sum>2*m&&(l-r>=2))
	{
		ans++;
		return;
	}
	for(long long i=l+1;i<=n;i++)
	{
		dfs(l,i,sum+a[i],max(m,a[i]));
	}
	for(long long i=r-1;i>=1;i--)
	{
		dfs(i,r,sum+a[i],max(m,a[i]));
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long x=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,3,0,a[1]);	
	cout<<ans+1;
	return 0;
}
	