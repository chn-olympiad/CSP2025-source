#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N=1e5+10,M=1e6+10,K=15;
int n,m,k;
int c[N<<1],head[N<<1],tot;
int a[K][N],fa[N<<1],p[N<<1];
int q[1<<12][N];
ll ans;
bool vis[N<<1];
inline int read() {
	register int x=0,f=1;
	register char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct edge {
	int u,v,w,nxt;
} e[M<<1];
inline bool cmp(edge x,edge y) {
	return x.w<y.w;
}
inline void add(int x,int y,int w) {
	e[++tot]=(edge) {
		x,y,w,head[x]
	};
	head[x]=tot;
}
inline int find(int x) {
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
inline void dfs(int s,int t,int p[],ll sum) {
	register int x,i,j,l,u,v,cnt=0;
	register ll res=0;
	//cout<<"bug"<<endl;
	for(i=1; i<=n+k; ++i)fa[i]=i,vis[i]=0;
	j=1;
	for(i=1; i<=m; ++i){
		while(t&&j<=n&&e[p[j]].w<=e[i].w) {
			u=find(e[p[j]].u),v=find(e[p[j]].v);
			if(u!=v) {
				fa[v]=u;
				if(vis[e[p[j]].u])++cnt;
				res+=e[p[j]].w;
				vis[e[p[j]].u]=1;
			}
			++j;
			if(cnt==n-1)break;
		}
		if(cnt==n-1) {
			//cout<<sum+res<<endl;
			ans=min(ans,sum+res);
			break;
		}
		u=find(e[i].u),v=find(e[i].v);
		if(u!=v) {
			fa[v]=u;
			res+=e[i].w;
			cnt++;
		}
		if(cnt==n-1) {
			//cout<<sum+res<<endl;
			ans=min(ans,sum+res);
			break;
		}
	}
	for(i=1;i<=n+k;++i)vis[i]=0;
	for(x=t+1; x<=k; ++x) {
		i=1,j=1;
		l=m+(x-1)*n;
		if(!t){
			for(j=1; j<=n; ++j) {
				q[s][j]=l+j;
			}
			dfs(s|(1<<(x-1)),x,q[s],sum+c[x]);
		} else {
			cnt=0;
			while(i<=n&&j<=n) {
				//cout<<i<<' '<<e[p[i]].v<<' '<<e[p[i]].w<<' '<<j<<' '<<e[l+j].v<<' '<<e[l+j].w<<endl;
				if(vis[e[p[i]].v]) {
					++i;
				} else if(vis[e[l+j].v]) {
					++j;
				} else if(e[p[i]].w<e[l+j].w) {
					//cout<<1<<endl;
					q[s][++cnt]=p[i];
					vis[e[p[i]].v]=1;
					++i;
				} else {
					//cout<<2<<endl;
					q[s][++cnt]=l+j;
					vis[e[l+j].v]=1;
					++j;
				}
			}
			for(i=1; i<=n; ++i)vis[i]=0;
			dfs(s|(1<<(x-1)),x,q[s],sum+c[x]);
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	register int i,x,y,w,j;
	n=read(),m=read(),k=read();
	for(i=1; i<=n+k; ++i) {
		fa[i]=i;
	}
	for(i=1; i<=m; ++i) {
		x=read(),y=read(),w=read();
		add(x,y,w);
	}
	sort(e+1,e+1+m,cmp);
	for(i=1; i<=k; ++i) {
		c[i]=read();
		for(j=1; j<=n; ++j) {
			a[i][j]=read();
			add(i+n,j,a[i][j]);
		}
		sort(e+m+(i-1)*n+1,e+m+i*n+1,cmp);
	}
	ans=1e18+10;
	dfs(0,0,p,0);
	printf("%lld\n",ans);
}
