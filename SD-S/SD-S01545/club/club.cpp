# include<bits/stdc++.h>
using namespace std;
const int MX = 1e5;
//long long dp[300][300];
int t;
int n;
int a[MX + 10];
int x;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	cout << t << endl;
	while(t--)
	{
		/*cout << 1111111111 << endl; 
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		long long ans = LLONG_MIN;
		for(int i = 1;i <= n;i++)
		{
			for(int j = n / 2;j >= 1;j--)
			{
				for(int k = n / 2;k >= 1;k--)
				{
					if(n - j - k > n / 2)
					{
						continue;
					}
					dp[j][k] = max(max(dp[j - 1][k] + a[i][0],dp[j][k - 1] + a[i][1]),dp[j][k] + a[i][2]);
					ans = max(ans,dp[j][k]);
				}
			}
		}
		cout << ans << endl;*/
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i] >> x >> x;
		}
		sort(a + 1,a + n + 1);
		long long ans = 0;
		for(int i = n;i > n / 2;i--)
		{
			ans+=a[i];
		}
		cout << ans << endl;
	}
	return 0;
 } 
