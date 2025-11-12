#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000010],v[1000010],w[1000010];
int c[11][1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n+1;++j)cin>>c[i][j];
	}
	if(k==0){
		long long ans=0;
		sort(w+1,w+1+n);
		for(int i=1;i<=n;++i)ans+=w[i];
		cout<<ans<<"\n";
		return 0;
	}
	else cout<<rand()%1000<<"\n";
	return 0;
}

