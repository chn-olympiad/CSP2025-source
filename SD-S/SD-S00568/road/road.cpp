#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a,b,c,d,e;
long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		ans+=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a>>b>>c>>d>>e;
	}
	printf("%lld",ans);
 	return 0;
}

