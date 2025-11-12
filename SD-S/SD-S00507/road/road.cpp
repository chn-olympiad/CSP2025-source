#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0;
long long u,v,w,c,a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u>>v>>w;
	for(int j=1;j<=k;j++){
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>a;
			ans+=a;
		}
	}
	cout<<ans;
	return 0;
}
