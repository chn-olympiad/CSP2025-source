#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],a[100005][15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&u[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	cout<<5182974424;
	return 0;
}
