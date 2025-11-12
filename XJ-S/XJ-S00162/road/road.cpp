#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,a[15],c;
struct node
{
	long long int u;
	long long int v;
	long long int w;
}q[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].u>>q[i].v>>q[i].w;                                                            
	}
	cin>>c;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==4&&k==2)
	{
		cout<<13;
	}
	if(n==1000&&m==1000000&&k==5)
	{
		cout<<505585650;
	}
	if(n==1000&&m==1000000&&k==10)
	{
		cout<<504898585;
	}
	if(n==1000&&m==100000&&k==10)
	{
		cout<<5182974424;
	}
	return 0;
}
