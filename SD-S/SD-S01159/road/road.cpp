#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int d[1000010][4],c[20],a[15][10010];
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>d[i][1]>>d[i][2]>>d[i][3];
		ans+=d[i][3];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	cout<<ans<<'\n';
	return 0;
} 
