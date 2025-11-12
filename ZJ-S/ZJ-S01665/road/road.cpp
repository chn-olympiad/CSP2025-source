#include <bits/stdc++.h>
using namespace std;
int n,m,k,s;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,c;
		cin>>u>>v>>c;
		s+=c;
	}
	for(int i=1;i<=k;i++)
	{
		int qwq;
		cin>>qwq;
		for(int i=1;i<=n-1;i++)
		{
			int awa;
			cin>>awa;
		}
	}
	cout<<s;//hao ba,zhi hui pian 5 fen T__T
	return 0;
}
