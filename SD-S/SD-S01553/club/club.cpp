#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 38;
inline int read()
{
	int num = 0,sign = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9')sign = ch == '-'?-1:1,ch = getchar();
	while(ch >= '0'&&ch <= '9')num = (num<<3)+(num<<1)+ch-'0',ch = getchar();
	return sign>0?num:-num;
}
int t,n,dp[MAXN][MAXN][MAXN][MAXN],a[MAXN][3],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t = read();
	while(t--)
	{
		n = read(),ans = 0;
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= n;i++)a[i][0] = read(),a[i][1] = read(),a[i][2] = read();
		for(int i = 1;i <= n;i++)
			for(int j = 0;j <= n/2;j++)
				for(int k = 0;k <= n/2;k++)
					for(int l = 0;l <= n/2;l++)
					{
						if(j > 0)dp[i][j][k][l] = max(dp[i-1][j-1][k][l]+a[i][0],dp[i][j][k][l]);
						if(k > 0)dp[i][j][k][l] = max(dp[i-1][j][k-1][l]+a[i][1],dp[i][j][k][l]);
						if(l > 0)dp[i][j][k][l] = max(dp[i-1][j][k][l-1]+a[i][2],dp[i][j][k][l]);
					}
		for(int j = 1;j <= n/2;j++)
			for(int k = 1;k <= n/2;k++)
				for(int l = 1;l <= n/2;l++)
					ans = max(ans,dp[n][j][k][l]);
		cout<<ans<<"\n";
	}
	return 0;
}
