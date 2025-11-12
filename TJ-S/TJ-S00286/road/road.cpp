#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[100005],v[100005],w[100005];
int c[100005],a[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a[1000005]={0};
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		int a[100005];
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	long long y=rand()%43624634+1;
	long long b=rand()%23589340+1;
	long long x=rand()%28479238+1;
	long long d=rand()%15493680+1;
	long long e=rand()%93946809+1;
	long long ans=(y+b+x+d+e)/5;
	return 0;
}
