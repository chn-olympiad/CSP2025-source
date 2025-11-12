#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5;
const int N = 2e2;
struct node
{int a,b,c,mxa,mxb,mxc;};
node x[MX + 10];
int dp[N + 10][N + 10][N + 10];
int a[MX + 10][3];
int b[MX + 10];
priority_queue<pair<int,int> > q;
bool cmp(const node &x,const node &y)
{
	if(x.mxa - x.mxb == y.mxa - y.mxb)
	{
		if(x.mxb - x.mxc == y.mxb - y.mxc)
			return x.a > y.a;
		return x.mxb - x.mxc > y.mxb - y.mxc;
	}
	return x.mxa - x.mxb > y.mxa - y.mxb;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,ans,fb,ff;
	int cnta,cntb,m;
	int cnt[4];
	scanf("%d",&t);
	while(t--)
	{
		fb = 1;
		ff = 1;
		scanf("%d",&n);
		for(int i = 1;i <= n;++i)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2])
				fb = 0;
			if(a[i][3])
				ff = 0;
		}
		if(n <= 200)
		{
			memset(dp,0,sizeof(dp));
			for(int i = 1;i <= n;++i)
			{
				for(int x = 0;x <= i;++x)
				{
					for(int y = 0;x + y <= i;++y)
					{
						if(x > n / 2 || y > n / 2 || (i - x - y) > n / 2)
							continue;
						if(x)
							dp[i][x][y] = max(dp[i][x][y],dp[i - 1][x - 1][y] + a[i][1]);
						if(y)
							dp[i][x][y] = max(dp[i][x][y],dp[i - 1][x][y - 1] + a[i][2]);
						if(i - x - y > 0)
							dp[i][x][y] = max(dp[i][x][y],dp[i - 1][x][y] + a[i][3]);
					}
				}
			}
			ans = 0;
			for(int i = 0;i <= n;++i)
			{
				for(int j = 0;i + j <= n;++j)
					ans = max(ans,dp[n][i][j]);
			}
			printf("%d\n",ans);
		}
		else if(fb && ff)
		{
			ans = 0;
			for(int i = 1;i <= n;++i)
				b[i] = a[i][1];
			sort(b + 1,b + n + 1);
			for(int i = n;i >= n / 2 + 1;--i)
				ans += b[i];
			printf("%d\n",ans);
		}
		else if(ff)
		{
			cnta = 0;
			cntb = 0;
			ans = 0;
			m = 0;
			for(int i = 1;i <= n;++i)
			{
				if(a[i][1] > a[i][2])
					cnta++;
				else
					cntb++;
				ans += max(a[i][1],a[i][2]);
			}
			if(cnta > n / 2)
			{
				for(int i = 1;i <= n;++i)
				{
					if(a[i][1] > a[i][2])
						b[++m] = a[i][1] - a[i][2];
				}
				sort(b + 1,b + m + 1);
				for(int i = 1;i <= m - n / 2;++i)
					ans -= b[i];
			}
			else if(cntb > n / 2)
			{
				for(int i = 1;i <= n;++i)
				{
					if(a[i][1] <= a[i][2])
						b[++m] = a[i][2] - a[i][1];
				}
				sort(b + 1,b + m + 1);
				for(int i = 1;i <= m - n / 2;++i)
					ans -= b[i];
			}
			printf("%d\n",ans);
		}
		else
		{
			memset(cnt,0,sizeof(cnt));
			for(int i = 1;i <= n;++i)
			{
				q.push({a[i][1],1});
				q.push({a[i][2],2});
				q.push({a[i][3],3});
				x[i].mxa = q.top().first;
				x[i].a = q.top().second;
				q.pop();
				x[i].mxb = q.top().first;
				x[i].b = q.top().second;
				q.pop();
				x[i].mxc = q.top().first;
				x[i].c = q.top().second;
				q.pop();
			}
			ans = 0;
			sort(x + 1,x + n + 1,cmp);
			for(int i = 1;i <= n;++i)
			{
				if(cnt[x[i].a] < n / 2)
				{
					ans += x[i].mxa;
					cnt[x[i].a]++;
				}
				else if(cnt[x[i].b] < n / 2)
				{
					ans += x[i].mxb;
					cnt[x[i].b]++;
				}
				else
				{
					ans += x[i].mxc;
					cnt[x[i].c]++;
				}
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
