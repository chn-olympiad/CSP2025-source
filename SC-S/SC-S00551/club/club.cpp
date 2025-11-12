#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int n;t--&&cin>>n;){
		ll ans=0;
		multiset<ll> m1,m2,m3;
		for(ll i=1,a,b,c;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c) m1.insert(a-max(b,c));
			else if(b>=c) m2.insert(b-max(a,c));
			else m3.insert(c-max(a,b));
			ans+=max({a,b,c});
		}
		if(m2.size()<m3.size()) swap(m2,m3);
		if(m1.size()<m2.size()) swap(m1,m2);
		while(m1.size()>n/2){
			ans-=*m1.begin();
			m1.erase(m1.begin());
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}