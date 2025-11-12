#include <bits/stdc++.h>
using namespace std;

long long c1[1000005],c2[1000005],prices;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,ans=0,a,b,c,d;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>c1[i]>>c2[i]>>prices;
		ans+=prices;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>prices>>a>>b>>c>>d; 
	}
	cout<<ans<<endl;
	return 0;
} 
