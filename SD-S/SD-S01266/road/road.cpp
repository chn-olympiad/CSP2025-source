#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+100,M=3e6+100;
int fa[N],n,m,k,c[20];
struct Ciallo{
	int u,v,w;
}edge[M];
int f(int x){
	if (x!=fa[x]) fa[x]=f(fa[x]);
	return fa[x];
}

int cmp(const Ciallo &p,const Ciallo &q){
	if (p.w<q.w) return 1;
	return 0;
}
void mer(int x,int y){
	x=f(x);y=f(y);
	fa[x]=y;
}
int read(){
	int x=0;
	char c='a';
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') {
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for (int i=0;i<N;++i) fa[i]=i;
	scanf("%d%d%d",&n,&m,&k);
	int i;
	for (i=1;i<=m;++i) {
		edge[i].u=read();
		edge[i].v=read();edge[i].w=read();
	}
	ll ans=0;
	for (int j=1;j<=k;++j){
		c[j]=read();
		ans+=c[j];
		for (int d=1;d<=n;++d,++i){
			edge[i].w=read();
			edge[i].u=j+n;
			edge[i].v=d;
		}
		
	}
	n+=k;
	sort(edge+1,edge+i,cmp);
	for (int l=1,j=1;l<n;++j){
		int u=edge[j].u,v=edge[j].v;
		if (f(u)==f(v))
			continue;
		++l;
		ans+=edge[j].w;
		mer(u,v);
	}
	printf("%lld",ans);
	return 0;
}

