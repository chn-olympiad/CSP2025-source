#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
const int N=5e5+10,M=2e6+10,MOD=1e9+7;
ll n,k,ans,a[N],b[N];
vector<ll> G[M];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		G[b[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		ll to=b[i-1]^k;
		ll idx=lower_bound(G[to].begin(),G[to].end(),i)-G[to].begin();
		if(idx<G[to].size()){
			ll minn=G[to][idx];
			for(int j=i+1;j<=G[to][idx];j++){
				ll To=b[j-1]^k;
				ll Idx=lower_bound(G[To].begin(),G[To].end(),j)-G[To].begin();
				if(Idx<G[To].size()) minn=min(minn,G[To][Idx]);
			}
			ans++;
			i=minn;
		}
	}
	cout<<ans;
}
int main(){
	IOS;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
