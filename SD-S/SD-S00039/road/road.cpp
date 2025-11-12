#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline int read(){
	int s=0,k=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*k;
}

bool aaaa;
const int N=1e4+5,M=1e6+5;
const ll inf=1e18;
int n,m,K,val[12],a[12][N],fa[N+20];
ll ans;
struct Edge{
	int u,v,w;
}edge[M],tmp[11*N];
bool bbbb;

bool ok(){
	for(int i=1;i<=K;i++)
		if(val[i]!=0) return 0;
	return 1;
}

int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

ll check(int S){
	int nn=n,m=n-1; ll res=0;
	for(int i=1;i<n;i++) tmp[i]=edge[i];
	for(int i=1;i<=K;i++){
		if(!(S>>i-1&1)) continue;
		res+=val[i];
		if(res>=ans) return inf;
		++nn;
		for(int j=1;j<=n;j++)
			tmp[++m]={nn,j,a[i][j]};
	}
	sort(tmp+1,tmp+1+m,[&](Edge x,Edge y){
		return x.w<y.w;
	});
	for(int i=1;i<=nn;i++) fa[i]=i;
	for(int i=1,cnt=0;i<=m&&cnt!=nn;i++){
		int u=tmp[i].u,v=tmp[i].v;
		int fx=find(u),fy=find(v);
		if(fx!=fy){
			res+=tmp[i].w;
			if(res>=ans) return inf;
			fa[fx]=fy;
			++cnt;
		}
	}
	return res;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();K=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		edge[i]={u,v,w};
	}
	sort(edge+1,edge+1+m,[&](Edge x,Edge y){
		return x.w<y.w;
	});
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,cnt=0;i<=m&&cnt!=n-1;i++){
		int u=edge[i].u,v=edge[i].v;
		int fx=find(u),fy=find(v);
		if(fx!=fy){
			fa[fx]=fy;
			edge[++cnt]=edge[i];
		}
	}
	for(int i=1;i<=K;i++){
		val[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	ans=inf;
	if(ok()) printf("%lld",check((1<<K)-1));
	else{
		for(int s=0;s<1<<K;s++) ans=min(ans,check(s));
		printf("%lld",ans);
	}
	return 0;
}

