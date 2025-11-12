#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int G1[10001][10001],c[10001],G2[10001][10001];
bool pd(int i){
	for(int j=1;j<=n;j++){
		if(G2[i][j]!=0){
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G1[u][v]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>G2[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		if(c[i]==0&&pd(i)){
			cout<<0<<endl;
			return 0;
		}
	}
	long long ans=INT_MAX;
	for(int i=1;i<=k;i++){
		long long sum=0;
		for(int j=1;j<=n;j++){
			sum+=G2[i][j];
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
