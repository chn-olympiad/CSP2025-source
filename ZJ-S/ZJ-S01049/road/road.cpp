#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=2e5+5;
const int M=1e6+5;
const int K=10005;
const ll inf=1e17+5;
int n,m,k,tot,a[N],f[N],c[15][K],ww[N];
ll ans;
int find(int x){
	return f[x]==x?f[x]:f[x]=find(f[x]);
} 
struct node{
	int u,v,w;
	inline bool operator <(const node &o) const{
		return w<o.w;
	}
}e[M];
node b[M],d[M];
inline ll get(int s){
	ll res=0;tot=n-1;
	for(int i=1;i<=tot;i++) b[i]=d[i];
	for(int i=1;i<=k;i++){
		int mi=(1<<(i-1));
		if((s&mi)==0) continue;
		res+=ww[i];
		for(int j=1;j<=n;j++) b[++tot]={n+i,j,c[i][j]};
	}
	sort(b+1,b+tot+1);
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=tot;i++){
		int u=find(b[i].u),v=find(b[i].v),w=b[i].w;
		if(u==v) continue;
		res+=w,f[u]=v;
	} 
	//printf("get:%d %d %lld\n",s,tot,res);
	return res;
}
void sol(){
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1),ans=0,tot=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		u=find(e[i].u),v=find(e[i].v),w=e[i].w;
		if(u==v) continue;
		ans+=w,d[++tot]=e[i],f[u]=v;
	} 
	for(int i=1;i<=k;i++){
		scanf("%d",&ww[i]);
		for(int j=1;j<=n;j++) scanf("%d",&c[i][j]); 
	}
	for(int s=1;s<(1<<k);s++) ans=min(ans,get(s));
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	//scanf("%d",&T);
	while(T--) sol();
	return 0;
}

