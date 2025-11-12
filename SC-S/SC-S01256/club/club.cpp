#include<bits/stdc++.h>
using namespace std;
#define man_what_can_I_say main()
#define manba_out 0
const int N=2e5+4;
int t;
int n;
int dp[205][205][205];//哇多么好的n^3暴力啊
int a1[N],a2[N],a3[N];

man_what_can_I_say
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					dp[i][j][k]=-INT_MAX;//多测不清空，亲人两行泪
				}
			}
			a1[i]=a2[i]=a3[i]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		dp[0][0][0]=0;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=min(n/2,i);j++)
			{
				for(int k=0;k<=min(n/2,i);k++){
					if(j+k>i)continue;
					if(j+1<=n/2)dp[i+1][j+1][k]=max(dp[i][j][k]+a2[i+1],dp[i+1][j+1][k]);
					if(k+1<=n/2)dp[i+1][j][k+1]=max(dp[i][j][k]+a1[i+1],dp[i+1][j][k+1]);
					if(i-j-k+1<=n/2)dp[i+1][j][k]=max(dp[i][j][k]+a3[i+1],dp[i+1][j][k]);
				//	cout<<dp[i][j][k]<<":"<<i<<" "<<j<<" "<<k<<endl;
					ans=max(dp[i][j][k],ans);	
				}
			}
		}
		cout<<ans<<endl;
		
	}
	return manba_out ;
}//孩子们你猜我会坠机吗