#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],dp[205][205][205],id[100005];
void baoli()
{
		memset(dp,0,sizeof dp);
		for(int k(1);k <= n;++k)
		{
			for(int i(0);i <= k;++i)
			{
				for(int j(0);j <= k-i;++j)
				{
					if(i) dp[k][i][j] = max(dp[k][i][j],dp[k-1][i-1][j]+a[k][0]);
					if(j) dp[k][i][j] = max(dp[k][i][j],dp[k-1][i][j-1]+a[k][1]);
					if(k-i-j > 0) dp[k][i][j] = max(dp[k][i][j],dp[k-1][i][j]+a[k][2]);
				}
			}
		}
		int ans(0);
		for(int i(0);i <= n;++i) for(int j(0);j <= n;++j) if(i <= n/2 and j <= n/2 and i+j >= n/2) ans = max(ans,dp[n][i][j]);
		cout << ans << "\n";
	return;
}
bool cmp(int x,int y)
{
	return max({a[x][0],a[x][1],a[x][2]}) > max({a[y][0],a[y][1],a[y][2]});
}
void tanxin()
{
		int ans(0),cnt1(0),cnt2(0),cnt3(0);
		sort(id+1,id+1+n,cmp);
		int i(1);
		for(;i <= n && cnt1 < n/2 && cnt2 < n/2 && cnt3 < n/2;++i)
		{
			if(a[id[i]][0] > max(a[id[i]][1],a[id[i]][2])) ans += a[id[i]][0],++cnt1;
			else if(a[id[i]][1] > max(a[id[i]][0],a[id[i]][2])) ans += a[id[i]][1],++cnt2;
			else ans += a[id[i]][2],++cnt3;
		}
		if(cnt1 == n/2)
		{
			for(;i <= n;++i)
			{
				if(a[id[i]][1] > a[id[i]][2]) ans += a[id[i]][1];
				else ans += a[id[i]][2];
			}
		}
		else if(cnt2 == n/2)
		{
			for(;i <= n;++i)
			{
				if(a[id[i]][0] > a[id[i]][2]) ans += a[id[i]][0];
				else ans += a[id[i]][2];
			}
		}
		else
		{
			for(;i <= n;++i)
			{
				if(a[id[i]][0] > a[id[i]][1]) ans += a[id[i]][0];
				else ans += a[id[i]][1];
			}
		}
		cout << ans << "\n";
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(cin >> t;t;--t)
	{
		memset(dp,0,sizeof dp);
		cin >> n;
		for(int i(1);i <= n;++i)
		{
			for(int j(0);j < 3;++j) cin >> a[i][j];
			id[i] = i;
		}
		if(n <= 200) baoli();
		else tanxin();
	}
}
