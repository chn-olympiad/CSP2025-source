//RP++ 1= Please!
//17:12 Luckily=100pts
#include<algorithm>
#include<stdio.h>
#include<string>
#define int long long
using namespace std;
const int maxn=2e4+5,maxc=15,maxe=2e6+5;
int n,m,ans,C,a[maxc],fa[maxn];
struct edge{
	int from,to,w;
	bool operator<(const edge &B)const{return w<B.w;}
}e[maxe];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int kruskal(int k){
	for(int i=1;i<=n+C;i++)fa[i]=i;
	int cnt=0,sum=0,node=n;
	for(int i=1;i<=C;i++)if((1<<(i-1)&k))node++,sum+=a[i];
	for(int i=1;i<=m;i++){
		if(e[i].from>n&&!((1<<(e[i].from-n-1))&k))continue;
		int fx=getfa(e[i].from),fy=getfa(e[i].to);
		if(fx==fy)continue;
		fa[fy]=fx;sum+=e[i].w;
		if(++cnt==node-1)break;
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),C=read();bool SubA=1;
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		e[i]=(edge){x,y,z};
	}
	for(int i=1;i<=C;i++){
		a[i]=read();
		if(a[i])SubA=0;
		for(int j=1;j<=n;j++){
			int x=read();
			e[++m]=(edge){i+n,j,x};
		}
	}
	sort(1+e,1+e+m);
	if(SubA)ans=kruskal((1<<C)-1);
	else{
		int MAX=1<<C;ans=0x7f7f7f7f7f7f7f7f;
		for(int k=0;k<MAX;k++)ans=min(ans,kruskal(k));
	}
	printf("%lld\n",ans);
	return 0;
}