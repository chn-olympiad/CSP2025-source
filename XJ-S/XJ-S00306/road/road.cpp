#include<bits/stdc++.h>
using namespace std;
struct road
{
	int cw[1000100],k=1;
}city[1000100];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	int u[1000100],w[1000100],v[1000100];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>v[i]>w[i];
		city[u[i]].cw[city[u[i]].k]=w[i];
		city[u[i]].k++;
		city[v[i]].cw[city[v[i]].k]=w[i];
		city[v[i]].k++;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<city[i].k)
		{
			sort(city[i].cw+1,city[i].cw+1+n);
			sum+=city[i],cw[1];
		}
		
	}
	cout<<sum<<endl;
	return 0;
}
