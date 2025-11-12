#include<iostream>
using namespace std;
struct node
{
	long long c1,c2,v;
}a[10000005];
int c[10000005],d[20][200005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].c1>>a[i].c2>>a[i].v;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>d[i][j];
	}
	int z=0;
	for(int i=1;i<=k;i++)
	{
		if(c[i]!=0)
			z=1;
		for(int j=1;j<=n;j++)
		{
			if(d[i][j]!=0)
				z=1;
		}
	}
	int w=0;
	if(z==0)
		cout<<w;
	return 0;
} 
