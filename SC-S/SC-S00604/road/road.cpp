#include <bits/stdc++.h>

using namespace std;

#define int long long 

inline int read(){
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	int res=0;
	while(c<='9'&&c>='0'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*f;
}

const int N=1e4+30,M=1e6+30,K=30;

struct Edge{
	int u,v,w;
}e[M*16];

int n,m,k;
int ecnt;
int c[N],a[N][K];
int fa[N];
int val[N][N];

void add(int u,int v,int w){
	e[++ecnt].u=u;
	e[ecnt].v=v;
	e[ecnt].w=w;
	return;
}

bool cmp(Edge x,Edge y){
	return x.w<y.w;
}

int ans=0;

int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy){
		return;
	}
	fa[fx]=fy;
	return;
}

void kruscal(){
	sort(e+1,e+ecnt+1,cmp);
	int cnt=0;
	for(int i=1;i<=ecnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)){
			continue;
		}
		merge(u,v);
		ans+=w;
		cnt++;
		if(cnt==n-1){
			break;
		}
	}
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			val[i][j]=INT_MAX;
		}
	}
	while(m--){
		int u=read(),v=read(),w=read();
		val[min(u,v)][max(u,v)]=min(val[u][v],w);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=k;i++){
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				val[l][r]=min(val[l][r],c[i]+a[i][l]+a[i][r]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(val[i][j]==INT_MAX){
				continue;
			}
			add(i,j,val[i][j]);
			add(j,i,val[i][j]);
		}
	}
	kruscal();
	cout<<ans<<'\n';
	return 0;
}//O(n+n^2+m+nk+n^2k+n^2+nmlogm) -> O((k+logn)nmlogm)这……能搞到分？ 