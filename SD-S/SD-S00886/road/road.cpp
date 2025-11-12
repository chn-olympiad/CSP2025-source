#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int r=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*x;
}
const int M=4e6+100;
const int N=1e4+10;
struct edge{
	int u,v,w;
}e[M]; 
int n,m,k,tot; 
int c[15];
int fa[N];
int ans;
int a[15][N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void join(int x,int y){
	fa[find(x)]=find(y);
}
void krus(){
	for(int i=1;i<=tot;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;	
			join(e[i].u,e[i].v);
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	tot=m;
	for(int j=1;j<=k;j++){
		c[j]=read();
		for(int i=1;i<=n;i++){
			e[++tot].u=n+j;
			e[tot].v=i;
			e[tot].w=read();
		}
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e+1,e+1+tot,cmp);
	krus();
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
return 0;
}

