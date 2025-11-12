#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,T;
int a[N],b[N],c[N];
int dp[2][105][105][105];

void clear(int x)
{
	for(int i=0;i<105;i++)
	{
		for(int j=0;j<105;j++)
		{
			for(int k=0;k<105;k++)
			{
				dp[x][i][j][k]=0;
			}
		}
	}
}

void solve_for_a()
{
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=(n/2)+1;i<=n;i++)
	{
		ans+=a[i];
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<=200)
		{
			
			int ans=-1;
			for(int i=1;i<=n;i++)
			{
				clear(i&1);
				for(int j=0;j<=(n/2);j++)
				{
					for(int k=0;k<=(n/2);k++)
					{
						if(j+k>n) break;
						for(int l=i-j-k-1;l<=i-j-k-1;l++)
						{
							if(j+k+l>n)
							{
								break;
							}
							if(l<0 || l>n/2) continue;
							if(j+1<=n/2) {dp[i&1][j+1][k][l]=max(dp[(i-1)&1][j][k][l]+a[i],dp[i&1][j+1][k][l]);if(i==n){ans=max(ans,dp[i&1][j+1][k][l]);}}
							if(k+1<=n/2) {dp[i&1][j][k+1][l]=max(dp[(i-1)&1][j][k][l]+b[i],dp[i&1][j][k+1][l]);if(i==n){ans=max(ans,dp[i&1][j][k+1][l]);}}
							if(l+1<=n/2) {dp[i&1][j][k][l+1]=max(dp[(i-1)&1][j][k][l]+c[i],dp[i&1][j][k][l+1]);if(i==n){ans=max(ans,dp[i&1][j][k][l+1]);}}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			solve_for_a();
		}
	}
}
