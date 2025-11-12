#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+15;
bool bg;
int n,m,k,c[15],a[15][maxn],fa[maxn],tot;
long long ans=1e18;
struct edge{int u,v,w,id;}e[maxn],ee[maxn];
bool ed;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fnd(int x){
	return x==fa[x]?x:fa[x]=fnd(fa[x]);
}
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i]=(edge){read(),read(),read()};
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			ee[++tot]=(edge){n+i,j,read(),i};
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v;
		if(fnd(x)!=fnd(y)){
			fa[fnd(x)]=fnd(y);
			ee[++tot]=e[i];
		}
	}
	sort(ee+1,ee+tot+1,cmp);
	for(int S=0;S<1<<k;S++){
		long long res=0;
		for(int i=1;i<=k;i++){
			if(S>>(i-1)&1) res+=c[i];
		}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=tot;i++){
			if(ee[i].id==0||(S>>(ee[i].id-1)&1)){
				int x=ee[i].u,y=ee[i].v;
				if(fnd(x)!=fnd(y)){
					fa[fnd(x)]=fnd(y);
					res+=ee[i].w;
				}
			}
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
