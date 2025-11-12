#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx,ans;
void dfs(int x,int t,int ma,int cnt)
{
	if(x==n+1)
	{
		if(cnt>=3)ans++;
		return;
	}
	int tt=max(ma,a[x]);
	if(a[x]+t>2*tt||cnt<2)
		dfs(x+1,t+a[x],tt,cnt+1);
	dfs(x+1,t,ma,cnt);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*maxx)cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}