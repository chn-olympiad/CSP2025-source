#include<bits/stdc++.h>
#define ll long long
#define maxn 10105
using namespace std;
namespace Super_Ultra_CZS_Office{
	inline int read(){
		int x=0;
		char ch=getchar();
		while(ch<'0'||ch>'9')ch=getchar();
		while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
		return x;
	}
	inline void write(ll x){
		if(x<0){putchar('-');x=-x;}
		if(x>=10)write(x/10);
		putchar(x%10+'0');return;
	}
}
using namespace Super_Ultra_CZS_Office;
int n,m,k,fa[maxn],siz[maxn],blocnt;
inline void init(){for(int i=1;i<=n+k;++i)fa[i]=i,siz[i]=1;return;}
inline int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int u,int v){
	if(u==v)return;
	if(siz[v]>siz[u])swap(u,v);
	fa[v]=u;siz[u]+=siz[v];--blocnt;
	siz[v]=0;return;
}
struct EDGE{int u,v,w;};
struct EDGEEX{int u,v,w,id;};
EDGE edge[1000005];
EDGEEX popo[1000005];
int cst[12],cntop;
ll ans=1e18;
inline bool cmp(EDGE A,EDGE B){return A.w<B.w;}
inline bool CMP(EDGEEX A,EDGEEX B){return A.w<B.w;}
bool vis[maxn];
inline void check(int S){
	for(int i=n+1;i<=n+k;++i)vis[i]=0;init();
	ll sum=0;blocnt=n;
	for(int i=1;i<=k;++i)if(S&(1ll<<(i-1))){
		vis[n+i]=1;
		sum+=cst[i];
		++blocnt;
	}
	if(sum>=ans)return;
	for(int i=1;i<=cntop;++i){
		if(popo[i].id!=0){if(!vis[n+popo[i].id])continue;}
		if(!vis[popo[i].u])continue;
		if(!vis[popo[i].v])continue;
		int u=find(popo[i].u),v=find(popo[i].v);
		if(u==v)continue;
		merge(u,v);sum+=popo[i].w;
		if(blocnt==1)break;
		if(sum>=ans)return;
	}
	ans=min(ans,sum);return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;++i){
		edge[i].u=read();
		edge[i].v=read();
		edge[i].w=read();
	}
	sort(edge+1,edge+1+m,cmp);
	init();ans=0;
	for(int i=1;i<=m;++i){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		u=find(u);v=find(v);
		if(u==v)continue;
		merge(u,v);ans+=w;
		popo[++cntop]={edge[i].u,edge[i].v,edge[i].w,0};
	}
	for(int i=1;i<=k;++i){
		cst[i]=read();int u=i+n;EDGE E;
		for(int j=1;j<=n;++j){
			E.u=u;E.v=j;E.w=read();
			popo[++cntop]={E.u,E.v,E.w,i};
		}
	}
	sort(popo+1,popo+1+cntop,CMP);
	for(int i=1;i<=n;++i)vis[i]=1;
	for(int S=1;S<(1ll<<k);++S)check(S);
	write(ans);
	return 0;
}
