#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=1e6+5,K=15;
inline void read(int &x){
	x=0;
	char tmp;
	do	tmp=getchar();
	while(tmp<'0'||tmp>'9');
	while(tmp>='0'&&tmp<='9'){
		x=x*10+tmp-'0';
		tmp=getchar();
	}
}
int n,m,k,c[K],tot;
ll ans;
struct edge{int u,v,w,idx=0;}e[M],ne[M];
bool cmp(edge x,edge y){return x.w<y.w;}
int fa[N+K],siz[N+K];
int root(int u){return u==fa[u]?u:fa[u]=root(fa[u]);}
bool combine(int u,int v){
	int x=root(u),y=root(v);
	if(x==y)	return 0;
	if(siz[x]<siz[y])	swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=n;++i){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;++i){
		read(e[i].u);
		read(e[i].v);
		read(e[i].w);
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;++i)
		if(combine(e[i].u,e[i].v)){
			ans+=e[i].w;
			ne[++tot]=e[i];
		}
	for(int i=1;i<=k;++i){
		read(c[i]);
		for(int j=1,w;j<=n;++j){
			read(w);
			ne[++tot]={n+i,j,w,i};
		}
	}
	sort(ne+1,ne+1+tot,cmp);
	for(int s=1;s<1<<k;++s){
		ll res=0;
		for(int i=1;i<=k;++i)
			if(s>>(i-1)&1)
				res+=c[i];
		for(int i=1;i<=n+k;++i){
			fa[i]=i;
			siz[i]=1;
		}
		for(int i=1;i<=tot;++i)
			if(!ne[i].idx||(s>>(ne[i].idx-1)&1))
				if(combine(ne[i].u,ne[i].v))
					res+=ne[i].w;
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}