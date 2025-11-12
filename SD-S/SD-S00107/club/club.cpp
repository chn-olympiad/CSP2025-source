#include<bits/stdc++.h>
#define MX 200000
using namespace std;
struct node
{
	int d;//满意度d
	int id;//部门编号 
};
node a[MX + 10][5];
int dp[MX + 10],cnt[MX + 10];
int f[MX + 10][5];
priority_queue<pair<int,int> > q[5];
bool cmp(node &x,node &y)
{
	return x.d < y.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,i,j;
	cin >> T;
	while(T--)
	{
		int n,ans = 0;
		cin >> n;
		for (i = 1;i <= n;i++)
		{
			for (j = 1;j <= 3;j++)
			{
				cin >> a[i][j].d;
				a[i][j].id = j;
			}
		}
		for (i = 1;i <= n;i++)
		{
			sort(a[i] + 1,a[i] + 3 + 1,cmp);
			node u = a[i][3];
			node v = a[i][2];
			dp[i] = u.d;
			cnt[u.id]++;
			q[u.id].push(make_pair(v.d - u.d,i));
		}
		for (i = 1;i <= 3;i++)
		{
			if (cnt[i] > n / 2)
			{
				while(cnt[i] > n / 2)
				{
					int u = -q[i].top().first;
					int pos = q[i].top().second;
					dp[pos] = a[pos][2].d;
					cnt[i]--;
					q[i].pop();
				} 
			}
		}
		for (i = 1;i <= n;i++)
		{
			ans += dp[i];
		}
		cout << ans << '\n';
		for (i = 1;i <= 3;i++)
		{
			while(!q[i].empty())
			{
				q[i].pop();
			}
		}
		for (i = 1;i <= n;i++)
		{
			dp[i] = cnt[i] = 0;
			for (j = 1;j <= 3;j++)
			{
				a[i][j].id = a[i][j].d = 0;
			}
		}
	}
	return 0;
}
/*




性质：不可能有1个以上的部门同时不满足条件 
*/






