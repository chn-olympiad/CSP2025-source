#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
	int x,y,z;
}a[100005];
int dp[201][101][101][101];
void solve()
{
	memset(dp,0,sizeof dp);
	dp[1][1][0][0]=a[1].x;
	dp[1][0][1][0]=a[1].y;
	dp[1][0][0][1]=a[1].z;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=min(i,n/2);j++)
		{
			for(int k=0;k+j<=i&&k<=n/2;k++)
			{
				int z=i-j-k;
				if(z>n/2)continue;
				if(j>0)
				{
					dp[i][j][k][z]=max(dp[i][j][k][z],dp[i-1][j-1][k][z]+a[i].x);
				}
				if(k>0)
				{
					dp[i][j][k][z]=max(dp[i][j][k][z],dp[i-1][j][k-1][z]+a[i].y);
				}
				if(z>0)
				{
					dp[i][j][k][z]=max(dp[i][j][k][z],dp[i-1][j][k][z-1]+a[i].z);
				}
			}
		}
	}

//		for(int i=2;i<=n;i++)
//		{
//			for(int j=0;j<=min(i,n/2);j++)
//			{
//				for(int k=0;k+j<=min(i,n/2)&&k<=n/2;k++)
//				{
//					if(i-j-k>n/2)continue;
//					cout<<dp[i][j][k][i-j-k]<<" ";
//				}
//				cout<<endl;
//			}cout<<endl;
//		}
//        cout<<dp[n][]
	int ans=0;
	for(int i=0;i<=n/2;i++)
	{
		for(int j=0;j+i<=n&&j<=n/2;j++)
		{
			if(n-i-j>n/2)continue;
			ans=max(ans,dp[n][i][j][n-i-j]);
		}
	}
//		for(int i=0;i<=n;i++)
//		{
//			for(int j=0;j<=n;j++)
//			{
//				for(int k=0;k<=n;k++)
//				{
//					for(int kk=0;kk<=n;kk++)
//					{
//						dp[i][j][k][kk]=0;
//					}
//				}
//			}
//		}
	cout<<ans<<endl;
	return ;
}
bool cmp(node a,node b)
{
	return max(a.x,a.y)>max(b.x,b.y);
}
bool cmp2(node a,node b)
{
	return a.y>b.y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--)
	{
		bool f=1,f2=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0)f2=0;
			if(a[i].z!=0)f=0;
		}
		if(f2)
		{
			sort(a+1,a+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].x;
			}
			cout<<ans<<endl;
		}
		else
		{
			solve();
		}
	}
	return 0;
}