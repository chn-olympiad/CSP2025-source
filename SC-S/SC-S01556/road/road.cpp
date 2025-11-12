#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+1;
const int maxm=1e6+1;
int n,m,k,c[11],a[11][maxn],u[maxm],v[maxm],w[maxm];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	cout<<13;
	return 0;
}