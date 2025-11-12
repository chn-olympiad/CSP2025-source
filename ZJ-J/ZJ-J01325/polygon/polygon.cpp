#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,maxn,a[5004],u[5004],sum;
bool check(int x,int y,int z)
{
	if(a[y]*2<x&&z>=3)
		return 1;
	return 0;
}
void dfs(int x,int y,int z)
{
	if(check(x,y,z))
		ans++;
	for(int i=1;i<=n;i++)
	{
		if(!u[i])
		{
			u[i]=1;
			dfs(x+a[i],a[i],z+1);
			u[i]=0;
		}
	}
}
signed main()
{
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxn=max(maxn,a[i]);
	sort(a+1,a+1+n);
	if(maxn==1)
	{
		for(int i=3;i<=n;i++)
		{
			sum=1;
			for(int j=1;j<=i;j++)
				sum=sum*(n-j+1)/j;
			ans+=sum;
		}
	}
	else if(n<=3)
	{
		if(n<3)
			cout<<0;
		else
			if(a[1]+a[2]+a[3]>a[3]*2)
				cout<<1;
	}
	else
		dfs(0,0,0);
	cout<<ans;
 	return 0;
}