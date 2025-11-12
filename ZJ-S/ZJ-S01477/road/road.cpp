#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10001,K=11,M=1000001,INF=INT_MAX;
int n,m,k,vst[N+K],u,v,ga,c[K],dist[N+K],w,uw,hd[N+K],nxt[M*2+N*K*2],cnt,cnth,tmp;
ll ans;
struct Point{ int v,w; };
Point ed[M*2+N*K*2],hp[4*(M*2+N*K*2)];
inline void adde(int uu,int vv,int ww){
	++cnt,ed[cnt]={vv,ww},nxt[cnt]=hd[uu],hd[uu]=cnt;
	++cnt,ed[cnt]={uu,ww},nxt[cnt]=hd[vv],hd[vv]=cnt;
}
inline void Push(Point x){
	tmp=++cnth,hp[tmp]=x;
	while(tmp)
		if(hp[tmp].w<hp[tmp>>1].w) swap(hp[tmp],hp[tmp>>1]),tmp>>=1;
		else return;
}
inline Point Top(){ return hp[1]; }
inline void Pop(){
	swap(hp[1],hp[cnth]),tmp=1,--cnth;
	while(tmp<=cnth)
		if((tmp<<1)<=cnth&&hp[tmp].w>hp[tmp<<1].w&&((tmp<<1|1)>cnth||hp[tmp<<1|1].w>hp[tmp<<1].w)) swap(hp[tmp],hp[tmp<<1]),tmp<<=1;
		else if((tmp<<1|1)<=cnth&&hp[tmp].w>hp[tmp<<1|1].w&&hp[tmp<<1].w>hp[tmp<<1|1].w) swap(hp[tmp],hp[tmp<<1|1]),tmp=tmp<<1|1;
		else return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(register int i=1;i<=n+k;++i) dist[i]=INF;
	for(register int i=1;i<=m;++i) cin>>u>>v>>w,adde(u,v,w);
	for(u=1;u<=k;++u){
		cin>>c[u];
		for(v=1;v<=n;++v) cin>>w,adde(u+n,v,w);
	}
	Push({1,0}),dist[1]=0,ans=0,ga=n;
	while(cnth){
		u=Top().v,uw=Top().w,Pop();
		if(!ga) break;
		if(vst[u]||uw>dist[u]) continue;
		vst[u]=1,ans+=1ll*uw,dist[u]=0,ga-=(u<=n);
		for(register int i=hd[u];i;i=nxt[i]){
			v=ed[i].v,w=ed[i].w;
			if(vst[v]) continue;
			if(v>n) w+=c[v-n];
			if(w<dist[v]) dist[v]=w,Push({v,w});
		}
	}
	cout<<ans;
	return 0;
}
