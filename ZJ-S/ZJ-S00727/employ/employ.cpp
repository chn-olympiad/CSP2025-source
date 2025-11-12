#include<bits/stdc++.h>
#define speed_up ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define N 2025111
#define M 998244353
using namespace std;
typedef long long ll;
ll n,m,dif[N],c[N],idx;
vector<ll>ready[N];
ll tmp_lst[N];
inline void solve(ll floor){
	if(floor==n){
		idx++;
		for(ll i=0;i<n;i++){
			ready[idx].push_back(tmp_lst[i]);
		}
		return;
	}
	for(ll i=1;i<=n;i++){
		bool tag=true;
		for(ll j=1;j<=floor;j++){
			if(i==tmp_lst[j]){
				tag=false;
				break;
			}
		}
		if(tag){
			tmp_lst[floor]=i;
			solve(floor+1);
			tmp_lst[floor]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	speed_up;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		char x; cin>>x;
		dif[i]=x-'0';
	}
	for(ll i=1;i<=n;i++) cin>>c[i];
	solve(0);
	ll ans=0;
	for(ll i=1;i<=idx;i++){
		ll res=0,tmp=0;
		for(ll j=0;j<n;j++){
			if(dif[j]==1&&c[ready[i][j]]>tmp){
				res++;
			}else{
				tmp++;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans%M;
	return 0;
}
/*
3 2
101
1 1 2
*/
