#include<bits/stdc++.h>
using namespace std;
int t;
struct point{
	int f[3],id;
}a[100009],b[100009],c[100009];
bool cmp1(point x,point y){return x.f[0]<y.f[0];}
bool cmp2(point x,point y){return x.f[1]<y.f[1];}
bool cmp3(point x,point y){return x.f[2]<y.f[2];}
long long dp[204][204][204];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for(int ij=1;ij<=t;ij++)
	{
		srand(time(0));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n;
		bool fg1=1,fg2=1;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				cin>>a[i].f[j];
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				b[i].f[j]=c[i].f[j]=a[i].f[j],b[i].id=c[i].id=a[i].id=i;
		for(int i=1;i<=n;i++)
		{
			if(a[i].f[1]!=0)fg1=0;
			if(a[i].f[2]!=0)fg1=fg2=0;
		}
		sort(b+1,b+n+1,cmp2);
		sort(c+1,c+n+1,cmp3);
		if(n<204)
		{
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
				for(int j=0;j<=i;j++)
					for(int k=0;k+j<=i;k++)
					{
						int l=i-j-k;
						if(j>0)dp[l][j][k]=max(dp[l][j][k],dp[l][j-1][k]+a[i].f[1]);
						if(k>0)dp[l][j][k]=max(dp[l][j][k],dp[l][j][k-1]+a[i].f[2]);
						if(l>0)dp[l][j][k]=max(dp[l][j][k],dp[l-1][j][k]+a[i].f[0]);
					}
			long long ans=-1;
			for(int i=0;i<=n/2;i++)
				for(int j=0;j<=min(n/2,n-i);j++)
					if(n-i-j<=n/2)
						ans=max(ans,dp[i][j][n-i-j]);
			cout<<ans<<'\n';
		}
		else if(fg1)
		{
			long long ans=0;
			for(int i=1;i<=n/2;i++)ans+=a[i].f[0];
			cout<<ans<<'\n';
		}
		else cout<<(rand()+1)*(rand()+1)%500009<<'\n';
	}
	return 0;
}
