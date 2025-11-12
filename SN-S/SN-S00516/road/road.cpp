//王美萱 SN-S00516 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,ans=0;
int u[N],v[N],w[N],c[N],a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=n+1;j++){
		cin>>c[j]>>a[j];
	}
	for(int i=1;i<=m;i++){
		ans+=n*u[i];
	}
	cout<<ans;
	return 0;
}
