#include<bits/stdc++.h>
using namespace std;
const int MX = 1e4,MN = 20;
struct edge
{
	int from,to,w;
};
bool cmp(edge a,edge b)
{
	return a.w < b.w;
}
edge e[(MX * MX) + 10];
int n,m,k,u,v,len,c[MN + 10][MX + 10],num[MX + 10],cnt,fa[MX + 10],ans;
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int a,int b)
{
	fa[find(a)] = b;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n;i++)
	{
		fa[i] = i;
	}
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&len);
		e[++cnt].from = u;
		e[cnt].to = v;
		e[cnt].w = len;
	}
	for (int i = 1;i <= k;i++)
	{
		scanf("%d",&num[i]);
		for (int j = 1;j <= n;j++)
		{
			scanf("%d",&c[i][j]);
		}
		for (int l = 1;l <= n;l++)
		{
			for (int r = l + 1;r <= n;r++)
			{
				e[++cnt].from = l;
				e[cnt].to = r;
				e[cnt].w = c[i][l] + c[i][r] + num[i];
			}
		}
	}
	sort(e + 1,e + cnt + 1,cmp);
	for (int i = 1;i <= cnt;i++)
	{
		int a = find(e[i].from),b = find(e[i].to);
		if (a == b)
		{
			continue;
		}
		ans += e[i].w;
		merge(e[i].from,e[i].to);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
