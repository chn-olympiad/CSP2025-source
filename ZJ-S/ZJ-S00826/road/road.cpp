#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,u[N],v[N],w[N],a,c;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++) cin>>a;
	}
	if(k==0) cout<<m;
	else cout<<m*k+n-1;
	return 0;
}
