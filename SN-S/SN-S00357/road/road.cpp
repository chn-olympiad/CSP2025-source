#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long a[10015][10015];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		for(int j=1;j<=n+k;j++)
		{
			a[i][j]=0x7fffffff;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		cin>>a[x][y];
		a[y][x]=a[x][y];
	}
	int xiang=n;
	if(k!=0)
	{
		for(int i=1;i<=k;i++)
		{
			int cjian;
			cin>>cjian;
			xiang++;
			for(int j=1;j<=n;j++)
			{
				cin>>a[xiang][j];
				a[xiang][j]+=cjian;
				a[j][xiang]=a[xiang][j];
			}
		}
	}
	for(int i=1;i<=xiang;i++)
	{
		for(int j=1;j<=xiang;j++)
		{
			for(int z=1;z<=xiang;z++)
			{
				if(a[j][z]>a[i][j]+a[i][z])
				{
					a[j][z]=a[i][j]+a[i][z];
				}
			}
		}
	}
	cout<<a[1][n];
	return 0;
}
