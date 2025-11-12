#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10005],b[15];
bool open[15];
ll n,m,k;
struct Edge{
	ll from;
	ll to;
	ll w;
	ll fl;
	Edge(ll from,ll to,ll w,ll fl){
		this->from=from;
		this->to=to;
		this->w=w;
		this->fl=fl;
	}
	ll getW()const{
		if(fl==0) return w;
		else return w+(open[fl]?0:b[fl]);
	}
	bool operator>(const Edge& e) const{
		return this->getW()>e.getW();
	}
};
ll in1,in2,in3;
priority_queue<Edge,vector<Edge>,greater<Edge> > pq;
struct UFS{
	vector<ll> v;
	vector<ll> z;
	UFS(ll n){
		v.resize(n+5);
		z.resize(n+5);
	}
	ll Find(ll x){
		return v[x]==0?x:v[x]=Find(v[x]);
	}
	void Union(ll x,ll y){
		ll px=Find(x);
		ll py=Find(y);
		if(px==py) return;
		if(z[px]>z[py]){
			v[py]=px;
		}
		else if(z[px]<z[py]){
			v[px]=py;
		}
		else{
			v[px]=py;
			z[px]++;
		}
	}
};
ll ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>in1>>in2>>in3;
		pq.push({in1,in2,in3,0});
	}
	for(ll i=1;i<=k;i++){
		cin>>b[i];
		for(ll j=1;j<=n;j++){
			cin>>a[j];
		}
		for(ll j=1;j<=n;j++){
			for(ll o=j+1;o<=n;o++){
				pq.push({j,o,a[j]+a[o],i});
			}
		}
	}
	UFS ufs(n);
	while(!pq.empty()){
		if(ufs.Find(pq.top().from)!=ufs.Find(pq.top().to)){
			ufs.Union(pq.top().from,pq.top().to);
			if(pq.top().fl==0){
				ans+=pq.top().w;
			}
			else{
				ans+=b[pq.top().fl]+pq.top().w;
				open[pq.top().fl]=true;
			}
		}
		pq.pop();
	}
	cout<<ans;
	return 0;
}
