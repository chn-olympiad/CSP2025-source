#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f*=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<3)+(x<<1)+(ch^48); ch=getchar(); }
	return x*f;
}
const int maxn=10010,maxm=1100010,maxk=20;
const int inf=1000000000000000000;
struct edge { 
	int u,v,w;
	friend bool operator <(const edge &a,const edge &b) { return a.w<b.w; }
	friend bool operator >(const edge &a,const edge &b) { return a.w>b.w; }
};
edge t[maxm];
priority_queue<edge,vector<edge>,greater<edge>> q;
int fa[maxn+maxk],c[maxk],co[maxk][maxn],tag[maxk];
int n,m,k,nown,nowm,cost,ans,sum;
int get(int x) {
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y) {
	int fx=get(x),fy=get(y);
	if(fx!=fy) fa[fx]=fy;
}
void kruskal() {
	while(q.size()) {
		int u=q.top().u,v=q.top().v,w=q.top().w; q.pop();
		if(get(u)==get(v)) continue;
		sum+=w; merge(u,v);
	}
}
void init() {
	for(int i=1;i<=k;i++) tag[i]=0;
	nown=n; nowm=m; sum=0; cost=0;
}
void solve(int s) {
	init();
	int bit=1,cost=0;
	while(s) {
		if(s&1) tag[bit]=1;
		bit++; s>>=1;
	}
	for(int i=1;i<=k;i++) {
		if(tag[i]==1) {
			cost+=c[i];
			int u=++nown;
			for(int v=1;v<=n;v++)
				t[++nowm]={u,v,co[i][v]};
		}
	}
	sum+=cost;
	for(int i=1;i<=nown;i++) fa[i]=i;
	for(int i=1;i<=nowm;i++) q.push(t[i]);
	kruskal();
	ans=min(ans,sum);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) {
		int u=read(),v=read(),w=read();
		t[i]={u,v,w};
	}
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++)
			co[i][j]=read();
	}
	ans=inf;
	for(int s=0;s<=(1<<k)-1;s++)
		solve(s);
	cout<<ans<<"\n";
	return 0;
}
