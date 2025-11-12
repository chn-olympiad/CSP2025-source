#include<bits/stdc++.h>
#define speed_up ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define N 400005
using namespace std;
typedef long long ll;
struct triple{
	ll v[4];
}cnt;
struct employ{
	pair<ll,ll>value[5];
}members[N];
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	return a.first>b.first;
}
ll ans,n;
inline void dfs(ll x,ll res,triple cnt){
	if(x==n+1){
		ans=max(ans,res);
		return;
	}
	for(ll i=1;i<=3;i++){
		if(cnt.v[members[x].value[i].second]+1<=n/2){
			cnt.v[members[x].value[i].second]++;
			dfs(x+1,res+members[x].value[i].first,cnt);
			cnt.v[members[x].value[i].second]--;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	speed_up;
	ll t;cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>members[i].value[1].first>>members[i].value[2].first>>members[i].value[3].first;
			members[i].value[1].second=1;members[i].value[2].second=2;members[i].value[3].second=3;
		}
		for(ll i=1;i<=n;i++){
			sort(members[i].value+1,members[i].value+1+3,cmp);
		}
		ans=0;
		dfs(1,0,{0,0,0,0});
		cout<<ans<<endl;
	}
	return 0;
}
