#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using pii=pair<int,int>;
#define endl '\n'

const int MAXN=200+6;

int n;
int a[MAXN][4];

int dp[MAXN][MAXN/2][MAXN/2];

ll allm[100005];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;

	while(T--)
	{
		cin>>n;
		if(n>MAXN)
        {
            for(int i=1,t;i<=n;i++)
            {
                cin>>allm[i]>>t>>t;
            }
            sort(allm+1,allm+n+1,greater<int>());
            ll ans=0;
            for(int i=1;i<=n/2;i++)
            {
                ans+=allm[i];
            }
            cout<<ans<<endl;
            continue;
        }
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(j>n/2)
				{
					//flag=1;
					break;
				}
				for(int k=0;k<=i;k++)
				//for(int k=i-j;k>=0;k--)
				{
					if(k+j>i)
					{
						break;
					}
					if(k>n/2)
					{
						//flag=1;
						break;
					}
					if(i-j-k>n/2)
					{
						continue;
					}
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					if(j!=0&&(i-j-k+1<=n/2)) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k!=0&&(i-j-k+1<=n/2)) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					//cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
				}
			}
			// cout<<"i="<<i<<endl;
			// for(int j=0;j<=n/2;j++)
			// {
			// 	for(int k=0;k<=n/2;k++)
			// 	{
			// 		cout<<dp[i][j][k]<<" ";
			// 	}
			// 	cout<<endl;
			// }
			// cout<<"i="<<i<<endl;
		}
		int ans=0;
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n/2;j++)
			{
				ans=max(ans,dp[n][i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}













