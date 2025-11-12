#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][3], dp[100005][3], cnt[100005][3][3];
int sum(int _a,int b,int c) {return _a+b+c;}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		memset(a,0,sizeof a);
		memset(dp,0,sizeof dp);
		memset(cnt,0,sizeof cnt);
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		dp[1][0]=a[1][0],cnt[1][0][0]++;
		dp[1][1]=a[1][1],cnt[1][1][1]++;
		dp[1][2]=a[1][2],cnt[1][2][2]++;
		for(int i = 2; i <= n; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int prev = 0; prev < 3; prev++)
				{
					if(cnt[i-1][k][prev]<n/2)
					{
						if(dp[i][k] < dp[i-1][prev] + a[i][k]) 
						{
							dp[i][k] = dp[i-1][prev] + a[i][k];
							cnt[i][k][0]=cnt[i-1][prev][0];
							cnt[i][k][1]=cnt[i-1][prev][1];
							cnt[i][k][2]=cnt[i-1][prev][2];
							cnt[i][k][k]++;
						}
					}
				}
			}
		}
		cout << max(max(dp[n][0],dp[n][1]),dp[n][2]) << endl;
	}
	fclose(stdin);
	fclose(stdout);
}	
// int tmpsel = -1;
			// for(int l = 0; l < 3; l++)
			// {
			// 	for(int j = 0; j < 3; j++)
			// 	{
			// 		cnt[i][j]=cnt[i-1][l];
			// 		if(cnt[i][j]<n/2) 
			// 		{
			// 			if(dp[i][l]<dp[i-1][j]+a[i][j]) 
			// 				{
			// 					dp[i][j] = dp[i-1][l]+a[i][j],tmpsel = j;
			// 				}
			// 		}
			// 			else 
			// 				{
			// 					dp[i][j]=max(dp[i][j],dp[i-1][l]);
			// 				}
			// 			cnt[i][tmpsel] = cnt[i-1][l]+1;
			// 			cerr << dp[i][j] <<' ';
			// 	}	
			// 	cnt[i][tmpsel]++;
			// }
			// cerr << "cnt = " <<cnt[i][0]<<' '<<cnt[i][1]<<' '<<cnt[i][2] << endl;
		// }
		// cout << max(max(dp[n][0],dp[n][1]),dp[n][2])<<endl;
