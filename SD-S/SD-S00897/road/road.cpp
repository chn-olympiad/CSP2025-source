#include<bits/stdc++.h>
using namespace std;
long long a[1005][1005],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			ans+=a[i][j];
		}
	}
	cout<<ans;
	return 0;
}

