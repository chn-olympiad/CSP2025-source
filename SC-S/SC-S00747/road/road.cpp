#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int NM = 2e4;
struct el{
	int u,v;
	ll w;
};
vector<el> E;
int F[NM+4];
int getF(const int &x){
	if(F[x] == x) return x;
	return F[x] = getF(F[x]);
}
bool cmp(const el &a,const el &b){
	return a.w < b.w;
}
ll ans,CS[NM+4];
set<int> pl,cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i = 1;i <= n+k;i++) F[i] = i;
	for(int i = 1;i <= m;i++){
		int u,v,w;cin>>u>>v>>w;
		E.push_back({u,v,w});
	}
	for(int i = 1,ak;i <= k;i++){
		cin>>CS[i];
		for(int j = 1;j <= n;j++) cin>>ak,E.push_back({n+i,j,CS[i]+ak});
	}
	m += n*k;
	sort(E.begin(),E.end(),cmp);
	for(int i = 0;i < m;i++){
		int fx = getF(E[i].u),fy = getF(E[i].v);
		if(fx != fy){
			F[fx] = fy;
			cnt.insert(E[i].u),cnt.insert(E[i].v);
			ans += E[i].w;
			if((E[i].u > n or E[i].v > n)){
				if(int(cnt.size()-pl.size()) > n) {ans -= E[i].w;continue;}
				if(E[i].u > n){
					if(pl.count(E[i].u)) ans -= CS[E[i].u-n];
					pl.insert(E[i].u);
				}
				if(E[i].v > n){
					if(pl.count(E[i].v)) ans -= CS[E[i].v-n];
					pl.insert(E[i].v);
				}
			}
		}
		if((int)cnt.size() >= n+k) break;
	}
	cout<<ans;
	return 0;
}
