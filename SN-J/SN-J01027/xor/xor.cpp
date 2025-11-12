#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[1005];
ll b[1005][1005];
typedef pair<ll,ll> P;
P q[1000005];
ll from[1000005];
ll end[1000005];
ll qi;
bool cmp(P p1,P p2){
	if(p1.second==p2.second){
		return p1.first<p2.first;
	}
	return p1.second<p2.second;
}
ll dp[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;++i) cin>>a[i];
	for(ll i=1;i<=n;++i){
		b[i][i]=a[i];
		if(b[i][i]==m){
			q[++qi]={i,i};
			continue;
		} 
		for(ll j=i+1;j<=n;++j){
			b[i][j]=b[i][j-1]^a[j];
			if(b[i][j]==m){
				q[++qi]={i,j};
				break;
			}
		}
	}
	sort(q+1,q+qi+1,cmp);
	ll maxx=-1;
	for(ll i=1;i<=qi;++i){
		from[i]=q[i].first;
		end[i]=q[i].second;
	}
	for(ll i=1;i<=qi;++i){
		ll last=lower_bound(end+1,end+qi+1,from[i])-end-1;
		dp[i]=max(dp[last]+1,dp[i-1]);
	}
	cout<<dp[qi];
	return 0;
}
