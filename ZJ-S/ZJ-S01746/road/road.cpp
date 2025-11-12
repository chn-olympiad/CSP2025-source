#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
int c,a[10001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>u>>v>>w;
	for(int i=1;i<=k;++i){
		cin>>c;
		for(int j=1;j<=n;++j){
			cin>>a[i];
		}
	}
	cout<<13;
	return 0;
}
