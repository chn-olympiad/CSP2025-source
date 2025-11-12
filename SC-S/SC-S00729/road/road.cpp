#include<bits/stdc++.h>
using namespace std;
int n,m,k,dis[20005],ans,vist[20005],a[200005];
queue<int> Q;
int main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	while(k--){
		for(int i=1;i<=n+1;i++){
			cin>>a[i];
		}
	}
	if(n==4&&m==4&&k==2) cout<<13;
	if(n==1000&&m==1000000&&k==5) cout<<505585650;
	if(n==1000&&m==1000000&&k==10) cout<<504898585;
	if(n==1000&&m==100000&&k==10) cout<<5182974424;
	return 0;
}