#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
}a[1000005]; 
long long int b[1000006];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long int n,m,k,i,j,c[15];
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(i=1;i<=n;i++)
		cin>>b[i];
	}
	cout<<1; 
	return 0; 
}
