#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k;
int u,v,w[N];
int x;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>u>>v>>w[i];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) cin>>x;
	}
	for(int i=1;i<=n;i++) ans+=w[i];
	cout<<ans;
	return 0;
}

