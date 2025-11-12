#include<bits/stdc++.h>
using namespace std;
int d[100001],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,x,y,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		d[i]=w;
	}
	sort(d+1,d+n+1);
	for(int i=1;i<=n-1;i++) ans+=d[i];
	cout<<ans;		
	return 0;
}