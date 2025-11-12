#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	int v=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v;
}
int n,m,k;
struct edge{
	int u,v,w;
	bool operator<(const edge &x)const{
		return w<x.w;
	}
}g[1100010],q[1100010];
int gtp=0;
int a[12][10010];
int fa[10010],sz[10010];
int find(int x){
	return fa[x]=fa[x]==x?x:find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,x,y,z;i<=m;i++){
		x=read(),y=read(),z=read();
		g[i]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		a[i][0]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			q[(i-1)*n+j]={n+i,j,a[i][j]};
		}
	}
	sort(q+1,q+k*n+1);
	sort(g+1,g+m+1);
	for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
	gtp=0;
	for(int i=1;i<=m;i++){
		int fx=find(g[i].u),fy=find(g[i].v);
		if(fx==fy) continue;
		g[++gtp]=g[i];
		if(sz[fx]<sz[fy]) fa[fx]=fy,sz[fy]+=sz[fx];
		else fa[fy]=fx,sz[fx]+=sz[fy];
	}
	for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
	for(int i=1;i<=k*n;i++){
		int fx=find(q[i].u),fy=find(q[i].v);
		if(fx==fy) continue;
		g[++gtp]=q[i];
		if(sz[fx]<sz[fy]) fa[fx]=fy,sz[fy]+=sz[fx];
		else fa[fy]=fx,sz[fx]+=sz[fy];
	}
	sort(g+1,g+gtp+1);
//	for(int i=1;i<=gtp;i++){
//		cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<endl;
//	}
	ll ans=1e18;
	for(int msk=0;msk<(1<<k);msk++){
		for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
		ll cur=0;
		for(int i=1;i<=k;i++){
			if(msk&(1<<(i-1))) cur+=(ll)a[i][0];
		}
		for(int i=1;i<=gtp;i++){
			if(g[i].u>n&&(msk&(1<<(g[i].u-n-1)))==0) continue;
			int fx=find(g[i].u),fy=find(g[i].v);
			if(fx==fy) continue;
			cur+=(ll)g[i].w;
			if(sz[fx]<sz[fy]) fa[fx]=fy,sz[fy]+=sz[fx];
			else fa[fy]=fx,sz[fx]+=sz[fy];
		}
		ans=min(ans,cur);
	}
	printf("%lld\n",ans);
	return 0;
}