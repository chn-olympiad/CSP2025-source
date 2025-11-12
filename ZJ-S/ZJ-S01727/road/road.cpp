#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	char ch=getchar();int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
const int maxn=1e4+20;
const int maxm=1e6+20;
// bool M1;
int n,m,tot,k;
struct Edge{
	int u,v,w;
	Edge(){}
	Edge(int U,int V,int W){u=U,v=V,w=W;}
	bool operator < (const Edge &b) const{return w<b.w;}
}e[maxm],ee[(1<<10)+5][maxn];
int mm[(1<<10)+5];
int c[15];
Edge a[15][maxn];
ll res[(1<<10)+5];
int fa[maxn],siz[maxn];
void init(int n){for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;}
int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
bool merge(int x,int y){
	x=fd(x),y=fd(y);
	if(x==y) return 0;
	if(siz[x]>siz[y]) swap(x,y);
	fa[x]=y,siz[y]+=siz[x];
	return 1;
}
// bool M2;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e[i]=Edge(u,v,w);
	}
	sort(e+1,e+m+1);
	init(n);
	ll ans=0;
	for(int i=1;i<=m;i++) if(merge(e[i].u,e[i].v)) ans+=e[i].w,ee[0][++mm[0]]=e[i];
	for(int i=0;i<k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int x=read();
			a[i][j]=Edge(n+i+1,j,x);
		}
		sort(a[i]+1,a[i]+n+1);
	}
	for(int msk=1;msk<(1<<k);msk++){
		int x=msk&-msk,id=__lg(x);
		init(n+k);
		int j=1; ll res=0;
		for(int i=1;i<=mm[msk^x];i++){
			while(j<=n&&a[id][j].w<ee[msk^x][i].w){
				if(merge(a[id][j].u,a[id][j].v)) res+=a[id][j].w,ee[msk][++mm[msk]]=a[id][j];
				j++;
			}
			if(merge(ee[msk^x][i].u,ee[msk^x][i].v)) res+=ee[msk^x][i].w,ee[msk][++mm[msk]]=ee[msk^x][i];
		}
		while(j<=n){
			if(merge(a[id][j].u,a[id][j].v)) res+=a[id][j].w,ee[msk][++mm[msk]]=a[id][j];
			j++;
		}
		for(int i=0;i<k;i++) if(msk&(1<<i)) res+=c[i];
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	// cerr<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
	// cerr<<((&M2)-(&M1))/1024.0/1024.0<<'\n';
	return 0;
}