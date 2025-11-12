#include<bits/stdc++.h>
using namespace std;
int n,m,a[100006],ans;
const int mod=998244353;
void dfs(int c,int d,int z)
{

	if(c>n)
	{
		if(d*2<z)
		{
			ans+=1;
		}
		return ;
	}
	dfs(c+1,d,z);
	dfs(c+1,a[c],z+a[c]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>100)
	{
		long long z=4,x=1;
		for(int i=4;i<=n;i++)
		{
			x=(x+z)%mod;
			z=(z*2+i-1)%mod;
		}
		cout<<x;
		return 0;
	}
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans/2;
	return 0;
}
