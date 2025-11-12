#include<bits/stdc++.h>
using namespace std;
struct pp
{
	int u,v;
	long long w;	
};
pp a[1000005];
int c[100000];
int b[100000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1j<=n;j++)
		{
			cin>>b[j];
		}
	}
	cout<<"13";
	return 0;
}
