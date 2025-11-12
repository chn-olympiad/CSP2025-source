//曹子睿 SN-S00301 浐灞第七初级中学 
#include<bits/stdc++.h>
using namespace std;

int n, m, k, ans, f = 0;
struct
{
	long long u, v, w;
}a[10010];
struct
{
	long long c;
	long long x, y, z, q;
}b[11];
int main()//把图忘了（kao 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[j].u >> a[j].v >> a[j].w;
		}
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> b[i].c >> b[i].x >> b[i].y >> b[i].z >> b[i].q;
	}
	if(k == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
					
			}
		}
	}
	return 0;
}
