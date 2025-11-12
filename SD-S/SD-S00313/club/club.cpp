#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;

const int N=1e6+10;
ll n,f[N][5],ff[N],ans;
struct Node{
	ll a1,a2,a3;
}w[N];
void init(){
	memset(f,0,sizeof(f));
	memset(ff,0,sizeof(ff));
}
ll dfs(ll step,ll a1s,ll a2s,ll a3s){
	if(step>n){return 0ll;}
	if(f[step][a1s]&&f[step][a2s]&&f[step][a3s]){
		return max({f[step][a1s],f[step][a2s],f[step][a3s]});
	}
	if(a1s>n/2||a2s>n/2||a3s>n/2)cerr<<a1s<<' '<<a2s<<' '<<a3s<<'\n';
	ll cntf1=f[step][1],cntf2=f[step][2],cntf3=f[step][3],stans=0;
	if(a1s<n/2){
		cntf1=max(f[step][1],dfs(step+1,a1s+1,a2s,a3s)+w[step].a1);
		f[step][1]=cntf1;
		stans=max(stans,f[step][1]);
	}
	if(a2s<n/2){
		cntf2=max(f[step][2],dfs(step+1,a1s,a2s+1,a3s)+w[step].a2);
		f[step][2]=cntf2;
		stans=max(stans,f[step][2]);
	}
	if(a3s<n/2){
		cntf3=max(f[step][3],dfs(step+1,a1s,a2s,a3s+1)+w[step].a3);
		f[step][3]=cntf3;
		stans=max(stans,f[step][3]);
	}
	return stans;
}
void dfsfi(int step,int sum,vector<int> vv){
	if(step>n){
		if(sum==ans){
			for(int i=1;i<=n;i++){
				ff[i]=vv[i-1];
			}
		}
		return;
	}
	vv.push_back(1);
	dfsfi(step+1,sum+w[step].a1,vv);
	vv.pop_back();
	vv.push_back(2);
	dfsfi(step+1,sum+w[step].a2,vv);
	vv.pop_back();
	vv.push_back(3);
	dfsfi(step+1,sum+w[step].a3,vv);
	vv.pop_back();
}
void solve(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>w[i].a1>>w[i].a2>>w[i].a3;
	}
	ans=dfs(1,0,0,0);
	cout<<ans<<'\n';
	dfsfi(1,0,{});
	for(int i=1;i<=n;i++){
		cerr<<ff[i]<<'\n';
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		init();
		solve();
	}

	return 0;
}

