#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u,v,w,ans=0,c[1000010],a[51][1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
