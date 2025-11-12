#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T;
int n,ans;
int dp[102][102][102],f[1005][1005];
struct Node{
	int fir,sec,thr;
}a[N];
bool cmp1(Node x,Node y)
{
	return x.fir>y.fir;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		bool fa=true,fb=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].fir>>a[i].sec>>a[i].thr;
			if(a[i].sec!=0) fa=false;
			if(a[i].thr!=0) fa=false,fb=false;
		}
		if(fa)
		{
			ans=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].fir;
			cout<<ans<<endl;
			continue;
		}
		else
		{
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
			{
				for(int j=n/2;j>=0;j--)
				{
					for(int k=n/2;k>=0;k--)
					{
						for(int l=n/2;l>=0;l--)
						{
							if(j>0) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i].fir);
							if(k>0) dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i].sec);
							if(l>0) dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i].thr);
						}
					}
				}
			}
			cout<<dp[n/2][n/2][n/2]<<endl;
		}
	}
	return 0;
}
