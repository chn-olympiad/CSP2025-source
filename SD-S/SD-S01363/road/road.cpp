
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
unsigned n,m,k,U,V,e[12][1005],W,c[12],e2[1005][1005],cnt,siz[1005];
char ch;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &rhs) const{
		return w<rhs.w;
	}
}E[1000005];
int fa[1005];
int get(int x){
	return (x==fa[x]?x:fa[x]=get(fa[x]));
}
void merge(int x,int y){
	int fx=get(x),fy=get(y);
	if(siz[fx]>siz[fy])swap(fx,fy);
	siz[fy]+=siz[fx];
	fa[fx]=get(fy);
}
inline unsigned int read(){
	unsigned int x=0;
	ch=getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	memset(e2,0x3f,sizeof e2);
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		U=read(),V=read(),W=read();
		e2[U][V]=e2[V][U]=min(e2[U][V],W);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			e[i][j]=read();
			for(int l=1;l<j;l++){
				e2[l][j]=min(e2[l][j],e[i][l]+e[i][j]+c[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			E[++cnt]={j,i,e2[j][i]};
		}
	}
	sort(E+1,E+cnt+1);
	int cnt2=0;
	long long ans=0;
	for(int i=1;i<=cnt && cnt2<n-1;i++){
		if(get(E[i].u)!=get(E[i].v)){
			merge(E[i].u,E[i].v);
			ans+=E[i].w,cnt2++;
		}
	}
	printf("%lld",ans);
	return 0;
}
