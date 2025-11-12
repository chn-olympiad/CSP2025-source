#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+2,K=12,N=1e4+1;
struct edge{
	int u,v,w;
}ro[M];
int a[K][N],ci[K],ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>ro[i].u>>ro[i].v>>ro[i].w;
	for(int i=1;i<=k;i++){
		cin>>ci[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
		/*
		what can I say???
		My about????
		*/
	}
	cout<<ans;
	return 0;
}