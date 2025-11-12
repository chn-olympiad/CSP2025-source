#include<bits/stdc++.h>
using namespace std;

struct road
{
	int city1,city2,cost;
}

bool nl[10010][10010];
road ml[1000010]
int kl[10][10010];
int n,m,k;


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>m[i].city1>>m[i].city2>>m[i].cost;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n+1;j++)
		{
			cin>>kl[i];
		}
	}
	
	return 0;
}
