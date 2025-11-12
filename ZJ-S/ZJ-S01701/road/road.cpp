#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	ll u,v,w,s=0;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		s+=w;
	}
	ll a;
	ll f=0;
	for(ll i=1;i<=k;i++){
		ll x;
		cin>>x;
	    
		ll f1=0,s1=0;
		for(ll j=1;j<=n;j++){
			cin>>a;
			s1+=a;
			if(a!=0) f1=1;
		}
		if(f1==0){
			cout<<x;
			return 0;
		}
		s=min(s,s1+x);
	}
	cout<<s;
	return 0;
}

