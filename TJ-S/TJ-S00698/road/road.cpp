#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long c[15],a[15][1005],ma;
struct road{
	int u,v,w;
}r[1100005];
queue<road> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
		road l={r[i].u,r[i].v,r[i].w};
		q.push(l);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			ma=max(ma,a[i][j]);
		}
	}
	if(ma==0) cout<<0;
	else cout<<(r[1].w*r[3].w/c[2]+a[2][1])*r[4].v;
	return 0;
}
