#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const ll N=2e4+10;
const ll M=2e6+10;
const ll INF=2147483647;
ll fa[N],n,m,k;
void init(){for(ll i=0;i<N;++i) fa[i]=i;}
ll findf(ll x){
	while(fa[x]^x) x=fa[x]=fa[fa[x]];
	return x;
}
struct node{ll from,to,w;}lin[M];
inline bool cmp(node x,node y){return x.w<y.w;}
vector<pair<ll,ll> > ks[15];
ll c[15],top[15];
struct E{
	ll w,id;
	friend bool operator >(const E a,const E b){
		return a.w>b.w;
	}
}td;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		lin[i].from=u,lin[i].to=v,lin[i].w=w;
	}
	sort(lin+1,lin+1+m,cmp);
	for(ll i=1;i<=k;++i){
		cin>>c[i];ll x;
		for(ll j=1;j<=n;j++){cin>>x;ks[i].push_back(make_pair(x,j));}
		sort(ks[i].begin(),ks[i].end()); 
	}
	ll ans=INF*INF,nans=0;
	for(ll i=0;i<(1LL<<k);++i){
		init();
		top[0]=1;
		ll al=n,cnt=0,ttpp;
		nans=0;
		priority_queue<E,vector<E>,greater<E> > q;
		for(ll j=0;j<k;j++){
			if((i>>j)&1){
				al++;
				nans+=c[j+1];
				top[j+1]=0;
				td.id=j+1,td.w=ks[j+1][0].first;
				q.push(td);
			}
		}
		td.id=0,td.w=lin[1].w;q.push(td);
		while(cnt<al-1){
			E now=q.top();q.pop();
			td.id=now.id;
			ttpp=top[now.id];
			if(now.id==0){
				if(top[0]<m){
					td.w=lin[++top[0]].w;
					q.push(td);		
				}
			}
			else{
				if(top[now.id]<n-1){
					td.w=ks[now.id][++top[now.id]].first;
					q.push(td);
				}
			}
			ll from,to;
			if(now.id==0) from=lin[ttpp].from,to=lin[ttpp].to;
			else from=n+now.id,to=ks[now.id][ttpp].second;
			from=findf(from),to=findf(to);
			if(from!=to){
				nans+=now.w;
				cnt++;
				fa[from]=to;
			} 
		}
		ans=min(ans,nans);
	}
	cout<<ans;
	return 0;
}
