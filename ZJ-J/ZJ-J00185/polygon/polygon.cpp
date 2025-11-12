#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int ans;
int f[5005];
void dfs(int step,int end)
{
	if(step>3)
	{
		int sum=0,maxx=INT_MIN;
		for(int i=1;i<=step-1;i++)
		{
			maxx=max(maxx,a[f[i]]);
			sum+=a[f[i]];
		}
		if(sum>2*maxx)
		{
			ans++;
		}
	}
	for(int i=end+1;i<=n;i++)
	{
		f[step]=i;
		dfs(step+1,i);
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
	dfs(1,0);
	cout<<ans;
	return 0;
}