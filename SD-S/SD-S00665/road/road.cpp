#include<bits/stdc++.h>
using namespace std;
const int MX = 2e6;
const int N = 1e4;
const int M = 10;
struct node
{
	int x,y;
	long long z;
};
long long c[M + 10],a[M + 10][N + 10];
node e[MX + 10];
int f[N + 10];
int getfa(int x)
{
	if(x == f[x])
		return x;
	return f[x] = getfa(f[x]);
}
int toge(int x,int y)
{
	x = getfa(x);
	y = getfa(y);
	if(x == y)
		return 0;
	f[y] = x;
	return 1;
}
bool cmp(const node &x,const node &y)
{
	return x.z < y.z;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,s,flg = 1,tot;
	long long ans = 0ll;
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 1;i <= m;++i)
		scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].z);
	for(int i = 1;i <= s;++i)
	{
		scanf("%lld",&c[i]);
		if(c[i])
			flg = 0;
		for(int j = 1;j <= n;++j)
			scanf("%lld",&a[i][j]);
	}
	for(int i = 1;i <= n;++i)
		f[i] = i;
	if(!s)
	{
		sort(e + 1,e + m + 1,cmp);
		for(int i = 1;i <= m;++i)
		{
			if(toge(e[i].x,e[i].y))
				ans += e[i].z;
		}
		printf("%lld\n",ans);
	}
	else if(flg)
	{
		tot = m;
		for(int i = 1;i <= s;++i)
		{
			for(int j = 1;j <= n;++j)
			{
				e[++tot].x = i + n;
				e[tot].y = j;
				e[tot].z = a[i][j];
			}
		}
		for(int i = n + 1;i <= n + s;++i)
			f[i] = i;
		sort(e + 1,e + (m + s * n) + 1,cmp);
		for(int i = 1;i <= m + s * n;++i)
		{
			if(toge(e[i].x,e[i].y))
				ans += e[i].z;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
