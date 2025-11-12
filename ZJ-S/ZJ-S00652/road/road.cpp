#include<bits/stdc++.h>
#define int long long

const int N=10010;
const int M=1000010;

const int K=15;
const int D=100020;

using namespace std;

int n,m,k,ans=1e18;

int tot;

int fa[N+K];

int c[K],f[K],t[K][N];

struct edge{
	int u,v,w;
	bool operator<(const edge &b)const{return w<b.w;}
}e0[M+D],e[M+D];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+(ch&15),ch=getchar();
	return ret*f;
}

int getfa(int x){
	return (fa[x]==x)?x:(fa[x]=getfa(fa[x]));
}

void _run(int x){
	int cnt=0,res=0;
	tot=0;
	for(int i=1;i<=m;i++)e[++tot]=e0[i];
	int tt=n+1;
	if(!x)tt--;
	for(int i=1;i<=k;i++)f[i]=(x>>(i-1))&1;
	for(int i=1;i<=k;i++){
		if(!f[i])continue;
		tt++;
		res+=c[i];
		for(int j=1;j<=n;j++)e[++tot]=(edge){n+i,j,t[i][j]};
	}
	
	sort(e+1,e+tot+1);
//	for(int i=1;i<=tot;i++)printf("%lld ",e[i].w);
//	printf("\n");
	
	for(int i=0;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++)fa[n+i]=0;
	for(int i=1;i<=tot;i++){
		int fx=getfa(e[i].u),fy=getfa(e[i].v);
		if(fx==fy)continue;
//		printf("Uni %lld %lld\n",e[i].u,e[i].v);
		fa[fx]=fy;
		res+=e[i].w;
		cnt++;
		if(cnt==tt-1)break;
	}
//	printf("res = %lld\n",res);
	ans=min(ans,res);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)e0[i].u=read(),e0[i].v=read(),e0[i].w=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)t[i][j]=read();
	}
	for(int x=0;x<(1<<k);x++)_run(x);
	printf("%lld\n",ans);
	return 0;
}










/*

luogu602458. 

Goodbye, world. 

*/
