#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const long long inf = 1e11;
int vis[10010];
int flag[110];
long long d[10010];
int head[10010];
int nx[2000010];
int to[2000010];
long long w[2000010];
long long spd1[110];
long long spd2[22][10010];
int E = 0;
void init()
{
	for(int i = 1;i <= n;i++)
	{
		head[i] = -1;
	}
}
void add(int a,int b,long long c)
{
	w[E] = c;
	to[E] = b;
	nx[E] = head[a];
	head[a] = E;
	E++;
}
struct node
{
	int id,step;
	bool operator < (const node &cmp) const
	{
		return step > cmp.step;
	}
};
priority_queue < node > q;
long long ret()
{
	for(int i = 1;i <= n;i++)
	{
		d[i] = inf;
	}
	node ww,vv;
	ww.id = 1;
	ww.step = 0;
	d[1] = 0;
	q.push(ww);
	long long sum = 0;
	while(!q.empty())
	{
		ww = q.top();
		q.pop();
		if(vis[ww.id])
		{
			continue;
		}
//		printf("%d %d\n",ww.id,ww.step);
		vis[ww.id] = 1;
		sum += ww.step;
		for(int it = head[ww.id];it != -1;it = nx[it])
		{
			if(w[it] < d[to[it]] && vis[to[it]] == 0)
			{
				d[to[it]] = w[it];
				vv.step = w[it];
				vv.id = to[it];
				q.push(vv);
			}
		}
//		printf("Q:\n");
		for(int i = 1;i <= k;i++)
		{
			for(int j = 1;j <= n;j++)
			{
//				printf("%d %d\n",j,spd2[i][ww.id] + spd2[i][j]);
				if(spd2[i][ww.id] + spd2[i][j] < d[j] && vis[j] == 0)
				{
					d[j] = spd2[i][ww.id] + spd2[i][j];
					vv.id = j;
					vv.step = spd2[i][ww.id] + spd2[i][j];
					q.push(vv);
				}
			}
		}
//		printf("\n\n");
	}
	return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d %d %d",&n,&m,&k);
	init();
	int a,b;
	long long c;
	for(int i = 1;i <= m;i++)
	{
		scanf("%d %d %lld",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
//	for(int i = 1;i <= n;i++)
//	{
//		printf("%d:\n",i);
//		for(int it = head[i];it != -1;it = nx[it])
//		{
//			printf("%d ",to[it]);
//		}
//		printf("\n");
//	}
	for(int i = 1;i <= k;i++)
	{
		scanf("%lld",&spd1[i]);
		for(int j = 1;j <= n;j++)
		{
			scanf("%lld",&spd2[i][j]);
		}
	}
	long long r = ret();
	printf("%lld",r);
	return 0;
}
/*
3 3 1
1 2 1
1 3 1
2 3 1
0 0 0 0
*/
/*
3 3 2
1 3 100
1 2 1000
2 3 4
0 1 0 3
0 2 43 2
*/
