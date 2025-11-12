//Li Ruisi SN-S00368 Xi'an Tieyi High School
#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mod (998244353)
#define int long long
using namespace std;
inline int read(){
	int n=0,s=1;
	char x=0;
	while((x=getchar())<'0'||x>'9')
		if(x=='-')
			s=-1;
	while(x>='0'&&x<='9'){
		n=(n*10)+(x^48);
		x=getchar();
	}
	return n*s;
}
void write(int n,char x=0){
	if(n<0){
		putchar('-');
		n=-n;
	}
	if(n>=10)write(n/10);
	putchar('0'+n%10);
	if(x)putchar(x);
}
struct Edge{
	int u,v,w;
	Edge(){u=v=w=0;}
	Edge(int _u,int _v,int _w){u=_u,v=_v,w=_w;}
	bool operator<(Edge x)const{return w<x.w;}
}edge[1000001],edge2[1000001];
int fa[10101];
int find(int i){return fa[i]==i?i:fa[i]=find(fa[i]);}
int co[11];
int c[11][10001];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
	sort(edge+1,edge+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cc=0;
	for(int i=1;i<=m;i++){
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u==v)continue;
		edge[++cc]=edge[i];
		fa[u]=v;
	}
	for(int i=1;i<=k;i++){
		co[i]=read();
		for(int j=1;j<=n;j++)c[i][j]=read();
	}
	for(int j=1;j<=cc;j++)edge2[j]=edge[j];
	int cnt=cc;
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)edge2[++cnt]=Edge(i+n,j,c[i][j]);
	sort(edge2+1,edge2+cnt+1);
	int minm=1e18;
	for(int s=0;s<(1<<k);s++){
		int ans=0;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int qwq=n-1;
		for(int i=1;i<=k;i++)if(s&(1<<(i-1)))ans+=co[i],qwq++;
		for(int i=1;i<=cnt;i++){
			if(edge2[i].u>n&&!(s&(1<<(edge2[i].u-n-1))))continue;
			int u=find(edge2[i].u),v=find(edge2[i].v);
			if(u==v)continue;
			ans+=edge2[i].w;
			qwq--;
			if(qwq==0||ans>minm)break;
			fa[u]=v;
		}
		minm=min(minm,ans);
	}
	write(minm);
	return 0;
}

