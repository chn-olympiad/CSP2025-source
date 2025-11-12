#include<bits/stdc++.h>
#include<map>
#define ll long long
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout) 
#define dbug cout<<"ok"
using namespace std;
const ll N=1e4+5;
ll n,m,k,a[11][N],fa[N],c[N];
struct node{
	ll u,v,w;
	bool operator<(const node& other)const{
		return w<other.w;
	}
};
unordered_map<ll,ll>g;

inline ll ask(ll d){
	if(fa[d]==d)return d;
	return fa[d]=ask(fa[d]);
}
inline void add(ll u,ll v){
	fa[ask(u)]=ask(v);
}
bool cmp(node a,node b){
	return a.w<b.w;
}

vector<node>ve;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fre("road");
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)fa[i]=i;
	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		ve.push_back((node){u,v,w});
		g.insert({(ll)u*N+v,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>a[i][j];
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				if(g.find((ll)j*N+k)==g.end())ve.push_back((node){j,k,(ll)c[i]+a[i][j]+a[i][k]});
				else if(g[(ll)j*N+k]<(ll)c[i]+a[i][j]+a[i][k])ve.push_back((node){j,k,(ll)c[i]+a[i][j]+a[i][k]});
			}
		}
	}
	sort(ve.begin(),ve.end(),cmp);
	ll ans=0;
	for(node eg:ve){
		ll u=eg.u,v=eg.v,w=eg.w;
		if(ask(u)!=ask(v))add(u,v),ans+=eg.w;
	}
	cout<<ans<<"\n";
	return 0;
} 