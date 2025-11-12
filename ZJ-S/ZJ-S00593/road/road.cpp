#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	ll sum=0;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	for(int i=1;i<=k;i++){
		ll c;
		cin>>c;
	}
	cout<<sum;
	return 0;
}
