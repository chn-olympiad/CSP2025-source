#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10,MOD=1e9+7;
ll n,m,k,a[20][N],c[N],fa[N];
bool made[20];
struct node{
	ll u,v,w;
	bool operator<(const node &x)const{return x.w<w;}
}L[M];
priority_queue<node> pq;
vector<node> PQ;
ll find(ll x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>L[i].u>>L[i].v>>L[i].w,pq.push(L[i]);
	for(int i=1;i<=n;i++) fa[i]=i;
	ll ans=0;
	while(pq.size()){
		node now=pq.top();
		pq.pop();
		ll fu=find(now.u),fv=find(now.v);
		if(fu!=fv){
			fa[fv]=fu; PQ.push_back(now);
			ans+=now.w;
		}
	}
	for(int i=0;i<PQ.size();i++) pq.push(PQ[i]);
	PQ.clear();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n+j;i++) fa[i]=i;
		ll sum=0;
		for(int i=1;i<=j;i++){
			if(made[i]) sum+=c[i];
			else if(i==j) sum+=c[i];
		}
		for(int i=1;i<=n;i++) pq.push({j+n,i,a[j][i]});
		while(pq.size()){
			node now=pq.top();
			pq.pop();
			ll fu=find(now.u),fv=find(now.v);
			if(fu!=fv){
				fa[fv]=fu; PQ.push_back(now);
				sum+=now.w;
			}
		}
		for(int i=0;i<PQ.size();i++) pq.push(PQ[i]);
		PQ.clear();
		if(ans>=sum){
			ans=sum;
			made[j]=true;
		}
	}
	cout<<ans;
}
int main(){
	IOS;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
