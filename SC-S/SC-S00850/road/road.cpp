#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500005;
ll n,m,k;
ll head[N],tot,f[N];
ll c[N];
ll g[11][10001];
struct Edge{
	ll u,v,w;
}edge[N];
void add(ll u,ll v,ll w){
	edge[++tot]={head[u],v,w};
	head[u]=tot;
}
ll ans,cnt;
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
ll find(ll x){return x==f[x]?x:f[x]=find(f[x]);}
void ku(){
	for(ll i=1;i<=tot;i++){
		ll x=find(edge[i].u);
		ll y=find(edge[i].v);
		if(cnt==n-1) return;
		if(x!=y){
			f[x]=y;
			ans+=edge[i].w;
			cnt++;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++) f[i]=i;
	for(ll i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		edge[++tot].u=x,edge[tot].v=y,edge[tot].w=z;
		edge[++tot].u=y,edge[tot].v=x,edge[tot].w=z;
	}
	for(ll j=1,num;j<=k;j++){
		cin>>c[j];
		for(ll i=1,x;i<=n;i++){
			cin>>x;
			g[j][i]=x;
		}
	}
	for(ll i=1;i<n;i++){
		for(ll j=i+1;j<=n;j++){
			ll min1=0x3f3f3f3f;
			for(ll s=1;s<=k;s++){
				min1=min(min1,g[s][i]+g[s][j]+c[s]);//i->s s->j 
			}
			edge[++tot].u=i,edge[tot].v=j,edge[tot].w=min1;
			edge[++tot].v=i,edge[tot].u=j,edge[tot].w=min1;
		}
	}
	sort(edge+1,edge+1+tot,cmp);
	ku();
	cout<<ans;
	return 0;
}