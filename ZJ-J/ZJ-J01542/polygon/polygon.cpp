#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[50005];
bool p[50005]={false};
void check()
{
	long long sum=0,maxs=0,num=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==true)
		{
			num++;
			sum+=a[i];
			maxs=max(maxs,a[i]);
		}
	}
	if(num>=3 && sum>maxs*2)
	{
		ans=(ans+1)%998244353;
	}
	return;
}
void dfs(int x)
{
	if(x==n+1)
	{
		check();
		return;
	}
	else
	{
		dfs(x+1);
		p[x]=true;
		dfs(x+1);
		p[x]=false;
		return;
	}
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
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
