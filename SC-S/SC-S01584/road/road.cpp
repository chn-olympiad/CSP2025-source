#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
int k,n,m,sum,ans;
int r[N][N],c[N][15],state[N][N];
void change ()
{
	int l = 1;
	while (l <= n)
	{
		int R = 1;
		if (R == l || state[l][R]) continue;
		int maxk = 0;
		for (int i = 1;i <= k;i ++)
		{
			maxk = max(maxk,c[R][k]+c[l][k]);
		}
		ans += max(maxk,r[l][R]);
		state[l][R] = 1;
		l ++;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= m;i ++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		r[u][v] = w;
		r[v][u] = w;
		sum += w;
	}
	for (int i = 1;i <= k;i ++)
	{
		int cc;
		scanf("%d",&cc);
		for (int i  =1;i <= n;i ++) scanf("%d",&c[i][cc]);
	}
	change ();
	printf("%d",ans);
	return 0;
}