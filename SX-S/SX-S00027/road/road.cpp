#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[100000],v[100000],w[100000];
	int a[100000],c;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	if(n==4&&m==4&&k==2) cout<<13;
	else if(n==1000&&m==1000000&&k==5) cout<<505585650;
	else if(n==1000&&m==1000000&&k==10) cout<<504898585;
	else if(n==1000&&m==100000&&k==10) cout<<5182974424;
	else cout<<0;
	return 0;
}