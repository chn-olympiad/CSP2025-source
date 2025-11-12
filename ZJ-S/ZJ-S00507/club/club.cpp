#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int T,n;
int a[N][3];
ll dp[205][205][205];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(n/2,i);j++)
			{
				for(int k=0;k<=min(n/2,i);k++)
				{
					if(j+k>i)continue;
					int o=i-j-k;
					if(o>min(n/2,i))continue;
					if(j>0)dp[j][k][o]=max(dp[j-1][k][o]+a[i][0],dp[j][k][o]);
					if(k>0)dp[j][k][o]=max(dp[j][k-1][o]+a[i][1],dp[j][k][o]);
					if(o>0)dp[j][k][o]=max(dp[j][k][o-1]+a[i][2],dp[j][k][o]);
//					cout<<j<<" "<<k<<" "<<o<<" "<<dp[j][k][o]<<endl;
				}
			}
		}
		ll mx=0;
		for(int j=0;j<=n/2;j++)
		{
			for(int k=0;k<=n/2;k++)
			{
				if(j+k>n)continue;
				int o=n-j-k;
				if(o>n/2)continue;
				mx=max(dp[j][k][o],mx);
			}
		}
		cout<<mx<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
