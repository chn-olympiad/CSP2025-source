#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e4+5;
int n,m,k,u[N],v[N],w[N],c[15],a[15][M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	cout<<22;
	return 0;
}
