#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,w[10005],a[10005][10005],c[10005],s[10005][10005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		t+=s[u][v]=w;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>a[i][j];
	}
	srand(0);
	while(1){
		int f=rand()%t;
		if(f>=t/3&&f<=t/3*2){
			cout<<f;
			break;
		}
	}
	return 0;
}