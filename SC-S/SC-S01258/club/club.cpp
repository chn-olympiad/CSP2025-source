#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
const int Maxn = 1e5+10;
int a[4][Maxn];
int dp[35][35][35][35];
int dp_[205][205][205];
bool cmp(int x, int y)
{return x > y;}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool flag2 = true, flag3 = true;
		for(int i = 1; i <= n; ++i)
		{
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			if(a[2][i]) flag2 = false;
			if(a[3][i]) flag3 = false;
		}
		if(n <= 30)
		{
			ll ans = 0;
			
			memset(dp, 0, sizeof(dp));
			for(int i = 1; i <= n; ++i)
			{
				for(int j = 0; j <= min(i, (n >> 1)); ++j)
				{
					for(int k = 0; k <= min(i, (n >> 1)); ++k)
					{
						for(int l = 0; l <= min(i, (n >> 1)); ++l)
						{
							if(l + j + k > i) continue; 
							if(j) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i- 1][j - 1][k][l] + a[1][i]);
							if(k) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k - 1][l] + a[2][i]);
							if(l) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l - 1] + a[3][i]);
							ans = max(ans, (ll)dp[i][j][k][l]);
						}
					}
				}
			}
			cout << ans << '\n';continue;
		}
		if(n <= 200 && flag3)
		{
			ll ans = 0;
			
			memset(dp_, 0, sizeof(dp_));
			for(int i = 1; i <= n; ++i)
			{
				for(int j = 0; j <= min(i, (n >> 1)); ++j)
				{
					for(int k = 0; k <= min(i, (n >> 1)); ++k)
					{
						if(j + k > i) continue; 
						if(j) dp_[i][j][k] = max(dp_[i][j][k], dp_[i - 1][j - 1][k] + a[1][i]);
						if(k) dp_[i][j][k] = max(dp_[i][j][k], dp_[i - 1][j][k - 1] + a[2][i]);
						ans = max(ans, (ll)dp_[i][j][k]);
					}
				}
			}
			cout << ans << '\n';continue;
		}
		if(flag2 && flag3)
		{
			ll ans = 0;
			sort(a[1] + 1, a[1] + 1 + n, cmp);
			for(int i = 1; i <= (n >> 1); ++i)
			{
				ans += a[1][i];
			}
			cout << ans << '\n';continue; 
		}
		cout << 0 << '\n';
	}
	return 0;
}