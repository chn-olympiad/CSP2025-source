#include <bits/stdc++.h>
using namespace std;
const int N=20025,M=1e6+5,K=12;
using ll=long long;
using pii=array<int,2>;
using piii=array<int,3>;
using piiii=array<int,4>;
using pll=array<ll,2>;
using plll=array<ll,3>;
int read() {
	int res=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return res*f;
}
int id(int a,int b) {
	return (a<<10)+b;
}
int n,m,k;
int c[K],a[K][N];
ll ans[N],real_ans=1e18,dist[N];
bool vis[N];
piii E[M],E1[M],E2[M<<1];
int pa[N],tt;
int find(int x) {
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int fa[N],fe[1<<K][N];
vector<int> G[N];
struct {
	int to,nxt,w;
} e[M<<3];
int head[N],tot;
void add(int a,int b,int c) {
	tot++;
	e[tot].to=b;
	e[tot].nxt=head[a];
	e[tot].w=c;
	head[a]=tot;
}
void dfs(int u,int pre) {
	for(int i=head[u]; i; i=e[i].nxt) {
		int v=e[i].to,w=e[i].w;
		if(v==pre)continue;
//		cerr<<"ok "<<u<<' '<<v<<'\n';
		fe[0][v]=w;
		fa[v]=u;
		dfs(v,u);
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1,x,y,z; i<=m; i++) {
		x=read(),y=read(),z=read();
//		add(x,y,z);
//		add(y,x,z);
		E[i]= {z,x,y};
	}
	for(int i=1; i<=k; i++) {
		c[i]=read();
		for(int j=1; j<=n; j++)a[i][j]=read();
	}
	sort(E+1,E+m+1);
	for(int i=1; i<=n; i++)pa[i]=i;
	for(int i=1,cc=0; i<=m; i++) {
		int x=find(E[i][1]),y=find(E[i][2]);
		if(x==y)continue;
//		cerr<<E[i][1]<<' '<<E[i][2]<<'\n';
		ans[0]+=E[i][0];
		pa[x]=y;
		add(E[i][1],E[i][2],E[i][0]);
		add(E[i][2],E[i][1],E[i][0]);
		if((++cc)==n-1)break;
	}
	if(k<=5) {
		for(int p=1,rn=n; p<(1<<k); p++) {
			tt=0;
			rn=n;
			ans[p]=0;
			tot=0;
			for(int i=1; i<=n+k; i++)head[i]=0;
			for(int i=1; i<=m; i++)add(E[i][1],E[i][2],E[i][0]),add(E[i][2],E[i][1],E[i][0]);
			for(int i=1; i<=k; i++) {
				if((p>>(i-1))&1) {
					for(int j=1; j<=n; j++) {
						E1[++tt]= {a[i][j],i+n,j};
						add(i+n,j,a[i][j]);
						add(j,i+n,a[i][j]);
					}
					rn++;
					ans[p]+=c[i];
				}
			}
			if(n<=1e3+1) {
				memset(dist,0x3f,sizeof dist);
				memset(vis,0,sizeof vis);
				dist[1]=0;
				for(int i=1; i<=rn; i++) {
					int now=-1;
					for(int j=1; j<=n+k; j++) {
						if(!vis[j]&&(now==-1||dist[j]<dist[now]))now=j;
					}
//					cerr<<dist[now]<<' '<<now<<'\n';
					ans[p]+=dist[now];
					vis[now]=1;
					for(int i=head[now]; i; i=e[i].nxt) {
						int v=e[i].to,w=e[i].w;
//						cerr<<"DE: "<<now<<' '<<v<<'\n';
						if(!vis[v]&&dist[v]>w)dist[v]=w;
					}
				}
			} else {
				merge(E+1,E+m+1,E1+1,E1+tt+1,E2+1);
				for(int i=1; i<=n+k; i++)pa[i]=i;
				for(int i=1,cc=0; i<=m+tt; i++) {
					int x=find(E2[i][1]),y=find(E2[i][2]);
					if(x==y)continue;
					//		cerr<<E[i][1]<<' '<<E[i][2]<<'\n';
					ans[p]+=E2[i][0];
					pa[x]=y;
					if((++cc)==rn-1)break;
				}
			}

		}
	} else {
//	exit(0);
		dfs(1,0);
//	exit(0);
		for(int i=1; i<(1<<k); i++) {
			int j=i-(i&-i),now=__lg(i&-i)+1,x=-1;
			ll cst=INT_MAX;
//		memcpy(fa[i],fa[j],sizeof fa[i]);
			memcpy(fe[i],fe[j],sizeof fe[i]);
			ans[i]=ans[j];
			for(int p=1; p<=n; p++) {
				if(x==-1||a[now][p]<cst)x=p,cst=a[now][p];
			}
			ans[i]=ans[i]+cst+c[now];
			for(int p=1; p<=n; p++) {
				if(p==x)continue;
				if(p!=1&&fe[i][p]>a[now][p]) {
					ans[i]-=fe[i][p];
//				fa[i][p]=now+n;
					fe[i][p]=a[now][p];
					ans[i]+=fe[i][p];
				}
				if(fe[i][x]>a[now][p]) {
					ans[i]-=fe[i][x];
//				fa[i][p]=now+n;
					fe[i][x]=a[now][p];
					ans[i]+=fe[i][x];
				}
			}
		}
	}
	for(int i=0; i<(1<<k); i++)real_ans=min(real_ans,ans[i]);
	cout<<real_ans<<'\n';
}