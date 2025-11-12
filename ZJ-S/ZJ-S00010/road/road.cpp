#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,u,v,w[1000001],i,s;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>w[i];
	}
	sort(w+1,w+m+1);
	for(i=1;i<n;i++)
	{
		s+=w[i];
	}
	cout<<s<<"\n";
	return 0;
}
/*

*/
