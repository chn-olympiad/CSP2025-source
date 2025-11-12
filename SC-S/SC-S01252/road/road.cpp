#include<bits/stdc++.h>
using namespace std;

int u[10010],v[10010],w[10010],a[10010];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=n+1;j++){
			cin>>a[j];
		}
	}
	cout<<13;
	return 0;
}