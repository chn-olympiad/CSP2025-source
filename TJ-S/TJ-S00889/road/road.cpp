#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[N],v[N],w[N];
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i]; 
	int ans=0;
	for(int i=1;i<=m;i++)
	ans+=w[i];
	cout<<ans; 
	return 0;
}
































































































