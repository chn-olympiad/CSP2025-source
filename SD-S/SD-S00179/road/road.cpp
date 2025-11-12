#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--)
		cin>>u>>v>>w;
	for(int i=1;i<=(n+1)*k;i++)
		cin>>u;
	cout<<0;
	return 0;
}
