#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f[205][105][105],n,tt,ans;
ll dp[100005][4],t[100005][4][4];
struct node{ll x[4];}a[100005];
ll dfs(int i,int aa,int b,int c)
{
	if(i==n+1)return 0;
	ll res=0;
	if(f[i][aa][b])return f[i][aa][b];
	if(aa+1<=n/2)res=max(res,dfs(i+1,aa+1,b,c)+a[i].x[1]);
	if(b+1<=n/2) res=max(res,dfs(i+1,aa,b+1,c)+a[i].x[2]);
	if(c+1<=n/2) res=max(res,dfs(i+1,aa,b,c+1)+a[i].x[3]);
//	cout<<i<<" "<<aa<<" "<<b<<" "<<c<<" "<<res<<"\n";
	return f[i][aa][b]=res;
}
bool cmp(node x,node y){return x.x[1]>y.x[1];}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tt;
	for(;tt--;)
	{
		cin>>n;
		ll f1=0;
		for(int i=1;i<=n;i++)cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3],f1+=a[i].x[2]+a[i].x[3];
		if(n<=200)
		{
			memset(f,0,sizeof(f));
			cout<<dfs(1,0,0,0)<<"\n";
			continue;
		}
		if(!f1)
		{
			sort(a+1,a+n+1,cmp);
			ll ans=0;
			for(int i=1;i<=n/2;i++)ans+=a[i].x[1];
			cout<<ans<<"\n";
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				if(t[i-1][k][j]<n/2)
				{
					if(dp[i-1][k]+a[i].x[j]>dp[i][j])
					{
						dp[i][j]=dp[i-1][k]+a[i].x[j];
						t[i][j][1]=t[i-1][k][1];
						t[i][j][2]=t[i-1][k][2];
						t[i][j][3]-t[i-1][k][3];
						t[i][j][j]++;
					}
				}
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";
	}
	return 0;
}
//60pts~100pts?
