#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int f[N][5], dp[N], st[5], ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	cout << t;
	while(t --)
	{
		int n;
		cin >> n;
		int wmax = n / 2;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= 3; j ++)
				cin >> f[i][j];		
		for(int i = n; i >= 1; i --)
		{
			if(st[1] < wmax && st[2] < wmax && st[3] < wmax)
			{
				int cnt = max(f[i][1], max(f[i][2], f[i][3]));
				ans += cnt;
				if(cnt == f[i][1])
					st[1] ++;
				else if(cnt == f[i][2])
					st[2] ++;
				else st[3] ++;
			}
			else if(st[1] < wmax && st[3] < wmax)
			{
				int cnt = max(f[i][1], f[i][3]);
				ans += cnt;
				if(cnt == f[i][1])
					st[1] ++;
				else st[2] ++;
			}
			else if(st[1] < wmax && st[2] < wmax)
			{
				int cnt = max(f[i][1], f[i][2]);
				ans += cnt;
				if(cnt == f[i][1])
					st[1] ++;
				else st[2] ++;
			}
			else if(st[2] < wmax && st[3] < wmax)
			{
				int cnt = max(f[i][3], f[i][2]);
				ans += cnt;
				if(cnt == f[i][3])
					st[3] ++;
				else st[2] ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//本地的CtrlV是^V，zbnyl。 
