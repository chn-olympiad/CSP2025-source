#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005],ans; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	//¶Á²»¶®Ìâ=£¨ 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<ans;
	return 0;
}
