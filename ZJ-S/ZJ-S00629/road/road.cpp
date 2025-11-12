#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll Min=0;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Min+=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		ll ans=0;
		cin>>c;
		ans+=c;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			ans+=x;
		}
		Min=min(Min,ans);
	}
	cout<<Min;
	return 0;
}
