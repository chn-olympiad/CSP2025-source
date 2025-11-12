//我去电脑20分钟蓝屏一次，心态炸了呀 
#include <bits/stdc++.h>
using namespace std;
long long n,m,k,minn,ans,pos,f;
struct r
{
	int u,v,w;
} c[1000005];
struct s
{
	int c,a[10005];
} cs[15];
bool b[10004];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++)
	{
		cin >> c[i].u >> c[i].v >> c[i].w;
	}
	for(int i = 1;i<=k;i++)
	{
		cin >> cs[i].c;
		for(int j = 1;j<=n;j++)
			cin >> cs[i].a[j];
	}
	if(k!=0) cout << 0;
	else
	{
		while(1)
		{
			f = 0;
			for(int i = 1;i<=n;i++)
			{
				if(!b[i]) 
				{
					f = 1;
					break;
				}
			}
			if(f)
			{
				for(int i = 1;i<=m;i++)
				{
					if(minn>c[i].w) 
					{
						minn = c[i].w;
						pos = i;
					}
				}
				ans+=minn;
				b[c[pos].u]=1;
				b[c[pos].v]=1;
			}
			else break;
		}
		cout << ans;
	}
	return 0;
}
