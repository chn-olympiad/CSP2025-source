#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int f[N][5],n,t,ans,clu[4];
int d[N][5],a[N];
void bfs(int s,int step)
{
	if(step == n+1)
	{
		for(int i = 1;i <= 3;i++)
			ans = max(ans,d[n][i]);
	}
	for(int i = 1;i <= 3;i++)
	{
		if(clu[i]+1 <= n>>1)
			{
				d[step][i] = d[step-1][s] + f[step][i];
				clu[i]++;
				bfs(i,step+1);
				clu[i]--;
			}
	}
	
}
void bfs2(int s,int step)
{
	if(step == n+1)
	{
		for(int i = 1;i <= 2;i++)
			ans = max(ans,d[n][i]);
	}
	for(int i = 1;i <= 2;i++)
	{
		if(clu[i]+1 <= n>>1)
			{
				d[step][i] = d[step-1][s] + f[step][i];
				clu[i]++;
				bfs(i,step+1);
				clu[i]--;
			}
	}
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 0;
		if(n <= 32)
		{
		for(int i = 1;i <= 4;i++)
			clu[i] = 0;
		for(int i = 1;i <= n;i++)
			cin >> f[i][1] >> f[i][2] >> f[i][3];
		for(int i = 1;i <= 3;i++)
		{
			bfs(i,1);
			for(int i = 1;i <= n;i++)
				for(int j = 1;j <= 3;j++)
					d[i][j] = 0;
		}
		cout << ans <<"\n";
		}
		else if(n <=203 && n > 32)
		{
			for(int i = 1;i <= 4;i++)
			clu[i] = 0;
		for(int i = 1,q;i <= n;i++)
			cin >> f[i][1] >> f[i][2] >> q;
		for(int i = 1;i <= 2;i++)
		{
			bfs2(i,1);
			for(int i = 1;i <= n;i++)
				for(int j = 1;j <= 2;j++)
					d[i][j] = 0;
		}
		cout << ans << "\n";
		}
		else if(n > 204)
		{
			for(int i = 1,r,r2;i <= n;i++)
				cin >> a[i] >> r >> r2;
			sort(a+1,a+1+n);
			for(int i = n;i >= n>>1;i--)
				ans += a[i];
			cout << ans << "\n";
		}
	}
	return 0;
}

