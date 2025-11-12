#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	ans=1e9;
	for(int i=1;i<=k;i++){
		int u;cin>>u;
		sum=0;
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			sum+=w;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
