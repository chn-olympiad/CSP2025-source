#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,w,c;
const int M=1e4+5;
long long Map[M][M];


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		Map[x][y]=w;
		Map[y][x]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	return 0;
}

