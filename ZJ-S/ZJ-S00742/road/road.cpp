#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
const int M=1e4+1;
int n,m,k;
long long ans;
int c[11],u[N],v[N],w[N],a[11][N];
int ma[M][M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ma[u[i]][v[i]]=ma[v[i]][u[i]]=w[i];
		ans+=w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	if(k==0){
	    cout<<ans;
	}
	return 0;
}
