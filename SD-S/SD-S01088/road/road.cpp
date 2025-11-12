#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
		}
	}
	cout<<ans;
	return 0;
} 
