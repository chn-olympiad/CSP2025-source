#include<bits/stdc++.h>
using namespace std;
const int max_n=1e4+12;
int n,m,k,u,v,w,c[12],aw;
int fa[max_n];
long long ans;
struct node{
	int u,v,w;
};
vector<node> G;
bool cmp(node a,node b){
	return a.w<b.w;
}
int find_(int x){
	return (fa[x]==x?x:fa[x]=find_(fa[x]));
}
void Kruskal(){
	sort(G.begin(),G.end(),cmp);
	for(auto nd:G){
		int u=nd.u,v=nd.v,w=nd.w;
		int fu=find_(u),fv=find_(v);
		if(fu!=fv){
			ans+=w;
			fa[fv]=fu;
		}
	}
} 
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar(); 
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		G.push_back({u,v,w}); 
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			aw=read();
			G.push_back({n+i,j,aw});
		}
	}
	Kruskal();
	printf("%lld\n",ans);
	return 0;
}
