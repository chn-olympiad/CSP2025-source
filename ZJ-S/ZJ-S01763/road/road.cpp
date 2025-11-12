#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}
/*
By ZJ-S01763.
Luogu UID:1086453.
*/
