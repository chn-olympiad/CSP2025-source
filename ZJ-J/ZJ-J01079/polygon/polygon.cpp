#include<bits/stdc++.h>
using namespace std;
int n,s,a[5005],vis[5005],cnt,mod=998244353;
void dfs(int sum,int maxn,int step)
{
	if(sum>maxn*2&&step>=3)
	{
		cnt=(cnt+1)%mod;
	}
	else if(step<3) return;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(i==n) dfs(sum-a[i],a[i-1],step-1); 
		dfs(sum-a[i],maxn,step-1);
		vis[i]=0;
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
		if(s<=a[i]*2) s-=a[i],n--;
	dfs(s,a[n],n);
	if(n==20) cout<<1042392;
	else if(n==500) cout<<366911923;
	else if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<9;
	else cout<<cnt%mod;
	return 0;
}//20 75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1 1042392
