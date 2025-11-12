#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
int n, t, x, y, z;
ll sum=0;

struct node
{
	int num;
	int dt;
}a[100010], b[100010], c[100010];
int at=0, bt=0, ct=0;

bool cmp(node x, node y)
{
	return x.dt<y.dt;
}

void init()
{
	sum=at=bt=ct=0;
}

void append(int x, int y, int z)
{
	if (x>y)
	{
		if (x>z)
		{
			a[at].num=x;
			a[at].dt=min(x-y, x-z);
			at++;
		}
		else
		{
			c[ct].num=z;
			c[ct].dt=z-x;
			ct++;
		}
	}
	else
	{
		if (y>z)
		{
			b[bt].num=y;
			b[bt].dt=min(y-x, y-z);
			bt++;
		}
		else
		{
			c[ct].num=z;
			c[ct].dt=z-y;
			ct++;
		}
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		init();
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			append(x, y, z);
		}
		for (int i=0;i<at;i++)
			sum+=a[i].num;
		for (int i=0;i<bt;i++)
			sum+=b[i].num;
		for (int i=0;i<ct;i++)
			sum+=c[i].num;
		if (at>n/2)
		{
			sort(a, a+at, cmp);
			for (int i=0;i<at-n/2;i++)
				sum-=a[i].dt;
		}
		else if (bt>n/2)
		{
			sort(b, b+bt, cmp);
			for (int i=0;i<bt-n/2;i++)
				sum-=b[i].dt;
		}
		else if (ct>n/2)
		{
			sort(c, c+ct, cmp);
			for (int i=0;i<ct-n/2;i++)
				sum-=c[i].dt;
		}
		printf("%lld\n", sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
