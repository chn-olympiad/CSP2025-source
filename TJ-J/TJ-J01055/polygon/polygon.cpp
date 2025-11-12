#include<bits/stdc++.h>
using namespace std;
int a[10009],used[10009];
int n,ans=0;
bool check()
{
	int maxn=0;
	int sum=0;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,a[i]*used[i]);
		sum+=a[i]*used[i];
		flag+=used[i];
	}
	if(flag<3||(2*maxn>=sum))
		return 0;
	return 1;
}
int dfs(int now)
{
	if(now==n+1)
	{
		ans+=check();
		return 0;
	}
	used[now]=0;
	dfs(now+1);
	used[now]=1;
	dfs(now+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	/*if(n==3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(2*max(max(a,b),c)<a+b+c)
			cout<<1;
		else
			cout<<0;
		return 0;
	}*/
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
