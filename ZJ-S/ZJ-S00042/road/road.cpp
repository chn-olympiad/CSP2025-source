#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read(){
	char ch=getchar();int f=1,ret=0;
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+(ch&15),ch=getchar();
	return f*ret;
}
int n,m,k;
struct Edge{
	int u,v,w;
	bool operator <(const Edge& o)const{return w<o.w;}
}e[1000005];
int fa[10005];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
ll ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int x=read(),y=read(),z=read();
			e[i]=(Edge){x,y,z};
		}
		sort(e+1,e+m+1);
		for(int i=1;i<=m;i++){
			int fx=getfa(e[i].u),fy=getfa(e[i].v);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=e[i].w;
			}
		}
		printf("%lld",ans);
	return 0;
}
