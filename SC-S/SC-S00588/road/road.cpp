#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#define int long long
using namespace std;
const int N=1e3+2;
struct edge{
	int u,v,w=LONG_LONG_MAX;
}ed[N*N];
int n,m,k,cnt,c[N],a[12][N],fa[N],ans;
int dire[N][N];
bool cmp(edge ta,edge tb){
	return ta.w<tb.w;
}
int fnd(int x){
	if (x==fa[x]) return x;
	return fnd(fa[x]);
}
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		if (u>v) swap(u,v);
//		ed[++cnt]={u,v,w};
		ed[++cnt].u=u,ed[cnt].v=v,ed[cnt].w=w;
		dire[u][v]=cnt;
	}
	for (int i=1;i<=k;++i){
		c[i]=read();
		for (int j=1;j<=n;++j){
			a[i][j]=read();
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=i+1;j<=n;++j){
			for (int kk=1;kk<=k;++kk){
				if (!dire[i][j]){
					dire[i][j]=++cnt;
					ed[dire[i][j]].u=i,ed[dire[i][j]].v=j;
				}
				ed[dire[i][j]].w=min(ed[dire[i][j]].w,c[kk]+a[kk][i]+a[kk][j]);
			}
		}
	}
	sort(ed+1,ed+cnt+1,cmp);
	for (int i=1;i<=n;++i){
		fa[i]=i;
	}
	for (int i=1;i<=cnt;++i){
		int u=ed[i].u,v=ed[i].v;
		if (fa[u]==fa[v]){
			continue;
		}
		fa[u]=fnd(v);
		ans+=ed[i].w;
	}
	cout<< ans;
	
	
	return 0;
}
