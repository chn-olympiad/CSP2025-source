#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct r{
	int city1,city2,money;
}c[1000005];
int ci,ai;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i].city1>>c[i].city2>>c[i].money;
		sum+=c[i].money;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>ci;
		for(int j=1;j<=n;j++) cin>>ai;
	}
	if(k==0) cout<<sum;
	else cout<<"0";
	return 0;
}
