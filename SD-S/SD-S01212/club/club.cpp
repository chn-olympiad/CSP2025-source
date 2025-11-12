#include <bits/stdc++.h>
using namespace std;
int a[100005][5],x[100005],b[100005],d[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int c[5] = {0};
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int maxa = max(a[i][1],max(a[i][2],a[i][3])),maxx = -1,maxc = -1;
			for(int j = 1;j <= 3;j++)
			{
				if(a[i][j] == maxa)
				{
					if(maxx == -1)
					{
						maxx = j;
						maxc = c[j];
					}
					else if(c[j] < maxc)
					{
						maxx = j;
						maxc = c[j];
					}
				}
			}
			x[i] = maxx;
			c[maxx]++;
		}//初步分配，保证每个成员满意度最多且部门人数尽量少（可能超过n/2）
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			ans += a[i][x[i]];
		}
		if(c[1] > n / 2)
		{
			int m = 0;
			for(int i = 1;i <= n;i++)
			{
				if(x[i] == 1)
				{
					b[++m] = min(a[i][1] - a[i][2],a[i][1] - a[i][3]);
				}
			}
			int k = c[1] - n / 2;
			sort(b + 1,b + m + 1);
			for(int i = 1;i <= k;i++)
			{
				ans -= b[i];
			}
		}
		else if(c[2] > n / 2)
		{
			int m = 0;
			for(int i = 1;i <= n;i++)
			{
				if(x[i] == 2)
				{
					b[++m] = min(a[i][2] - a[i][1],a[i][2] - a[i][3]);
				}
			}
			int k = c[2] - n / 2;
			sort(b + 1,b + m + 1);
			for(int i = 1;i <= k;i++)
			{
				ans -= b[i];
			}
		}
		else if(c[3] > n / 2)
		{
			int m = 0;
			for(int i = 1;i <= n;i++)
			{
				if(x[i] == 3)
				{
					b[++m] = min(a[i][3] - a[i][1],a[i][3] - a[i][2]);
				}
			}
			int k = c[3] - n / 2;
			sort(b + 1,b + m + 1);
			for(int i = 1;i <= k;i++)
			{
				ans -= b[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
