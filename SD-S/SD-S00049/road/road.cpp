#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+9;
int n,m,k,c,u,v,w,sss[maxn];
int a[maxn],b[maxn][maxn],ss[maxn][maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int s=0;
	for(int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		b[u][v] = w;
	}
	for(int i = 1;i <= m-2;i++)
	{
		cin >> c >> a[i];
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			
				sss[i] = ss[i][j] ;
				if(sss[i] != s)
				{
					s += sss[i];
					
				}
				
			
		}
	}
	cout << s;
	return 0;
}
