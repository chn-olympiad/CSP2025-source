#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road1.in","r",stdin);
	long long n,m,k,u,v,w,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}
