#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
namespace FastIO{
	const int N=1<<21;
	char ibuf[N],*p1=ibuf,*p2=ibuf;
	char readChar(){
		if(p1!=p2) return *(p1++);
		p1=ibuf,p2=ibuf+fread(ibuf,1,N,stdin);
		return (p1==p2)?EOF:*(p1++);
	}
	int read(){
		char ch; int x=0;
		do ch=readChar();
		while(ch<'0'||ch>'9');
		while(ch>='0'&&ch<='9')
			x=x*10+(ch-'0'),ch=readChar();
		return x;
	}
}
using FastIO::read;
const int N=10020,M=(int)1e6+5,P=10;
struct Edge{
	int u,v,w,p;
	bool operator<(const Edge& t) const{
		return w<t.w;
	}
}e1[M],e2[(P+2)*N];
int n,m,p,len2,a[P],b[P][N];
namespace DSU{
	int fa[N];
	void init(int n){
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int u){
		return (fa[u]==u)?u:(fa[u]=find(fa[u]));
	}
	void merge(int u,int v){
		if(find(u)!=find(v)) fa[fa[u]]=fa[v];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j; long long ans=0,sum;
	n=read(),m=read(),p=read();
	for(i=1;i<=m;i++) e1[i].u=read(),e1[i].v=read(),e1[i].w=read();
	for(i=0;i< p;i++)
		for(a[i]=read(),j=1;j<=n;j++) b[i][j]=read();
	sort(e1+1,e1+m+1),DSU::init(n),len2=0;
	for(i=1;i<=m;i++){
		if(DSU::find(e1[i].u)==DSU::find(e1[i].v)) continue;
		ans+=e1[i].w,DSU::merge(e1[i].u,e1[i].v);
		e2[++len2]={e1[i].u,e1[i].v,e1[i].w,-1};
	}
	for(i=0;i< p;i++)
		for(j=1;j<=n;j++) e2[++len2]={n+i+1,j,b[i][j],i};
	sort(e2+1,e2+len2+1);
	for(i=1;i<(1<<p);i++){
		DSU::init(n+p),sum=0;
		for(j=0;j<p;j++) if(i>>j&1) sum+=a[j];
		for(j=1;j<=len2;j++){
			if(e2[j].p>=0&&!(i>>e2[j].p&1)) continue;
			if(DSU::find(e2[j].u)==DSU::find(e2[j].v)) continue;
			sum+=e2[j].w,DSU::merge(e2[j].u,e2[j].v);
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}