#include<bits/stdc++.h>
#define gc getchar()
#define LL long long
using namespace std;
const int MXM = 2e2 + 10;
inline int rd()
{
	int x = 0;
	char s = gc;
	while (!isdigit(s))
		s = gc;
	while (isdigit(s))
	{
		x = (x << 3) + (x << 1) + s - '0';
		s = gc;
	}
	return x;
}
int t, n, a[MXM][5];
int dp[MXM][MXM >> 1][MXM >> 1][MXM >> 1];
bool vis[MXM][MXM][MXM];
struct node
{
	int x, y ,z;
};
queue<node> q;
int DP()
{
	int mx = n >> 1;
	int mxx, mxy, mxz;
	int smx, smy, smz;
	int lmx, lmy, lmz;
	int ans;
	for (int i = 0; i <= mx; i++)
	{
		dp[i][0][0][0] = 0;
		dp[i][1][0][0] = 0;
		dp[i][0][1][0] = 0;
		dp[i][0][0][1] = 0;
	}
	q.push({1, 0, 0});
	q.push({0, 1, 0});
	q.push({0, 0, 1});
	int jj, kk, ll, j, k, l;
	while (!q.empty())
	{
//		jj = q.front().x;
//		kk = q.front().y;
//		ll = q.front().z;
//		j = jj & 1;
//		k = kk & 1;
//		l = ll & 1;
		j = q.front().x;
		k = q.front().y;
		l = q.front().z;
		q.pop();
		if (vis[j][k][l])
			continue;
		if (j + k + l > n)
			continue;
		for(int i = 1; i <= n; i++)
		{
			
			smx = a[i][1];
			smy = a[i][2];
			smz = a[i][3];
			if (j == 0)
			{
				lmx = 0;
				mxx = 0;
				smx = 0;
			}
			else
			{
				lmx = dp[i - 1][j - 1][k][l];
				mxx = dp[i - 1][j][k][l];
			}//x
			if (k == 0)
			{
				lmy = 0;
				mxy = 0;
				smy = 0;
			}
			else
			{
				lmy = dp[i - 1][j][(k - 1)][l];
				mxy = dp[i - 1][j][k][l];
			}//y
			if (l == 0)
			{
				lmz = 0;
				mxz = 0;
				smz = 0;
			}
			else
			{
				lmz = dp[i - 1][j][k][(l - 1)];
				mxz = dp[i - 1][j][k][l];
			}//z
			dp[i][j][k][l] = max(lmx + smx, mxx);
			dp[i][j][k][l] = max(dp[i][j][k][l], max(lmy + smy, mxy));
			dp[i][j][k][l] = max(dp[i][j][k][l], max(lmz + smz, mxz));
			ans = max(ans, dp[i][j][k][l]);
			//visit new unit
			vis[j][k][l] = 1;
			if (!vis[j + 1][k][l] && j != mx)
				q.push({j + 1, k, l});
			if (!vis[j][k + 1][l] && k != mx)
				q.push({j, k + 1, ll});
			if (!vis[j][k][l + 1] && l != mx)
				q.push({j, k, l + 1});
			//check
//			printf("dp[%d]{%d, %d, %d (%d, %d, %d)} = %d, ", i, j, k, l, j, k, l, dp[i][j][k][l], ans);
//			printf("smx/y/z = %d/%d/%d, ", smx, smy, smz);
//			printf("lmx/y/z = %d/%d/%d, ", lmx, lmy, lmz);
//			printf("mxx/y/z = %d/%d/%d\n", mxx, mxy, mxz);
		}
	}
	return ans;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = rd();
	int ans;
	for (int i = 1; i <= t; i++)
	{
		memset(vis, 0, sizeof(vis));
		n = rd();
		for (int j = 1; j <= n; j++)
		{
			a[j][1] = rd();
			a[j][2] = rd();
			a[j][3] = rd();
		}
		ans = DP();
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
