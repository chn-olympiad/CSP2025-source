#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5,MN = 10;
typedef struct
{
	long long int num;
	int id;
}node;
node b[MX + 10];
bool cmp(node u,node v)
{
	return u.num < v.num;
}
long long int a[MX + 10][MN + 10],n,T,cnt[MN + 10],ans,c[MX + 10],len;
int f(int x)
{
	if (a[x][1] >= a[x][2] && a[x][1] >= a[x][3])
	{
		return 1;
	}
	if (a[x][2] >= a[x][3] && a[x][2] >= a[x][1])
	{
		return 2;
	}
	return 3;
}
int rf(int x)
{
	if ((a[x][1] >= a[x][2] && a[x][1] <= a[x][3]) || (a[x][1] >= a[x][3] && a[x][1] <= a[x][2]))
	{
		return 1;
	}
	if ((a[x][2] >= a[x][1] && a[x][2] <= a[x][3]) || (a[x][2] >= a[x][3] && a[x][2] <= a[x][1]))
	{
		return 2;
	}
	return 3;
}
void change(int x)
{
	len = 0;
	for (int i = 1;i <= n;i++)
	{
		if (c[i] == x)
		{
			b[++len].num = abs(a[i][c[i]] - a[i][rf(i)]);
			b[len].id = i;
		}
	}
	sort(b + 1,b + len + 1,cmp);
	for (int i = 1;i <= (len - (n >> 1));i++)
	{
		ans -= b[i].num;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while (T--)
	{
		ans = 0;
		scanf("%lld",&n);
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= 3;j++)
			{
				scanf("%lld",&a[i][j]);
			}
			c[i] = f(i);
			cnt[c[i]]++;
			ans += a[i][c[i]];
		}
		for (int i = 1;i <= 3;i++)
		{
			if (cnt[i] > (n >> 1))
			{
				change(i);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
