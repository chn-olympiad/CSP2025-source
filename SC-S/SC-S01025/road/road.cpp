#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;cin>>n>>m>>k;
	for(int i=0,u,v,w;i<m&&cin>>u>>v>>w;i++)ans+=w;
	cout<<ans;
	return 0;
}