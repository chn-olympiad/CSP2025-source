#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define u32 unsigned int
#define u64 unsigned ll
const int N = 500;
const ll mod = 998244353;
int n,m,k,c[N + 5],cnt[N + 5];
u32 dp[N + 5][N + 5],g[N + 5][N + 5],ans;
int f[N + 5];
char a[N + 5];
void Mod(u32 &a){if(a >= mod)a -= mod;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i = 0;i < n;i++)cin>>c[i];
	for(int i = 0;i < n;i++)
		if(a[i] == '1')k++;
	for(int i = 0;i < n;i++)
		for(int j = c[i];j <= n;j++)cnt[j]++;
	dp[0][0] = 1;
	for(int i = 0;i <= n;i++)
	{
		if(a[i] == '1')
		{
			memcpy(g,dp,sizeof(g));
			memset(dp,0,sizeof(dp));
			for(int j1 = 0;j1 <= i;j1++)
			for(int j2 = 0;j2 <= i;j2++)
				if(g[j1][j2])
				{
					if(cnt[i - j1] > j2)dp[j1][j2 + 1] = (dp[j1][j2 + 1] + (u64)(cnt[i - j1] - j2) * g[j1][j2]) % mod;
					Mod(dp[j1 + 1][j2] += g[j1][j2]);
					if(cnt[i - j1] > j2)dp[j1 + 1][j2 + 1] = (dp[j1 + 1][j2 + 1] + (u64)(cnt[i - j1] - j2) * (mod - g[j1][j2])) % mod;
				}
		}
	}
	for(int j2 = 0;j2 <= n;j2++)
	{
		u32 res = 0;
		for(int j1 = m;j1 <= n;j1++)
			Mod(res += dp[j1][j2]);
		for(int j = 1;j <= n - j2;j++)
			res = (u64)j * res % mod;
		Mod(ans += res);
	}
	cout<<ans<<"\n";
}