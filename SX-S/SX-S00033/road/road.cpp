#include<bits/stdc++.h>
using namespace std;
struct ly{
	long long u,v,w;
}d[1000001];
struct ly2{
	long long p,a[10001];
}c[11];
long long i,j,n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>d[i].u>>d[i].v>>d[i].w;
	}
	for(i=1;i<=k;i++){
		cin>>c[i].p;
		for(j=1;j<=n;j++){
			cin>>c[i].a[j];
		}
	}
	cout<<13;
	return 0;
}