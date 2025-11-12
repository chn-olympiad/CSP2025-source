#include<cstdio>//40pts?plz!
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int fr(){
	int c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int x=0;
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
const int N=1e4+15,M=1e6+5,K=11;
struct edge{
	int u,v,w;
};
edge e[N*K+M];
int cnt;
int c,a;
void add_edge(int u,int v,int w){
	e[++cnt]=edge{u,v,w};
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[N];
int find_(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find_(fa[x]);
}
void merge_(int a,int b){
	fa[find_(a)]=find_(b);
}
bool same_(int a,int b){
	return find_(a)==find_(b);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=fr();v=fr();w=fr();
		add_edge(u,v,w);
	}
	for(int i=1;i<=k;i++){
		c=fr();
		for(int j=1;j<=n;j++){
			a=fr();
			add_edge(n+i,j,a);
		}
	}
	sort(e+1,e+1+cnt,cmp);
	long long cost=0;
	int merged=0;
	for(int i=1;i<=cnt;i++){
		if(merged>=(n+k-1)) break;
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(!same_(u,v)){
			merge_(u,v);
			merged++;
			cost+=w;
		}
	}
	printf("%lld",cost);
	return 0;
}
