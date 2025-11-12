#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	x=ch^48;
	ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int maxn=1e5+15;
int n,m,k;
struct edge{
	int v,w;
};
vector<edge> vec[maxn];
int dis[maxn],w[maxn],pre[maxn];
int imp[15];
bool vis[maxn];
struct node{
	int now,d;
	friend bool operator<(node x,node y){
		return x.d>y.d;
	}
};
const int maxe=2e6+5;
struct ed{
	int u,v,w;
}e[maxe];
int cnt=0;
bool cmp(ed x,ed y){
	return x.w<y.w;
}
int fa[maxn];
int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
int tmp[maxn];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	if(k==0){
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			e[i].u=read(),e[i].v=read(),e[i].w=read();
		}
		sort(e+1,e+m+1,cmp);
		int cnt=0,ans=0;
		for(int i=1;i<=m;i++){
			if(cnt==n-1)break;
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy)continue;
			cnt++;
			fa[fy]=fx;
			ans+=e[i].w;
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		int c;
		c=read();
		int bel;
		for(int j=1;j<=n;j++){
			tmp[j]=read();
			if(!tmp[j])bel=j;
		}
		for(int j=1;j<=n;j++){
			if(j==bel)continue;
			e[++cnt].u=bel,e[cnt].v=j,e[cnt].w=tmp[j];
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int ccn=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(ccn==n-1)break;
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		ccn++;
		ans+=e[i].w;
		fa[fy]=fx;
	}
	cout<<ans<<endl;
	return 0;
}
