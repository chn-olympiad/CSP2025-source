#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9+7;
int n;
int a[N][5];
ll dp[3][205][205][205];
ll ans;
int cnt1,cnt2;
ll b[N];
struct node{
	ll s1,s2;
}c[N];
void solve2()
{
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i][1];
	}
	sort(b+1,b+n+1,greater<ll>());
	ans=0;
	for(int i=1;i<=n/2;i++) ans+=b[i];
	cout<<ans<<"\n";
}
bool cmp(node x,node y)
{
	ll t1=max(x.s1,x.s2);
	ll t2=max(y.s1,y.s2);
	return t1>t2?1:0;
}
void solve()
{
	cnt1=cnt2=0;
	ans=0;
	memset(dp,0,sizeof dp);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++) 
		{
			cin>>a[i][j];	
			if(j==2 && a[i][j]==0) cnt1++;
			if(j==3 && a[i][j]==0) cnt2++;
		}
	}
	if(cnt1==n && cnt2==n)
	{
		solve2();
		return ;
	} 
	dp[1][1][0][0]=a[1][1];
	dp[1][0][1][0]=a[1][2];
	dp[1][0][0][1]=a[1][3];
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i && j<=n/2;j++)
		{
			for(int k=0;k<=i-j && k<=n/2;k++)
			{
				for(int z=0;z<=i-j-k && z<=n/2;z++)
				{
					dp[i&1][j+1][k][z]=max(dp[(i-1)&1][j][k][z]+a[i][1],dp[i&1][j+1][k][z]);
					dp[i&1][j][k+1][z]=max(dp[(i-1)&1][j][k][z]+a[i][2],dp[i&1][j][k+1][z]);
					dp[i&1][j][k][z+1]=max(dp[(i-1)&1][j][k][z]+a[i][3],dp[i&1][j][k][z+1]);	
					ll t1=dp[i&1][j+1][k][z],t2=dp[i&1][j][k+1][z],t3=dp[i&1][j][k][z+1];
					if(j+1<=n/2) ans=max(ans,t1);
					if(k+1<=n/2) ans=max(ans,t2);
					if(z+1<=n/2) ans=max(ans,t3);
				}
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
} 
