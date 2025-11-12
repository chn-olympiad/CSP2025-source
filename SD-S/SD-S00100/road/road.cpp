#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
typedef long long ll;
const int N=2e4+10,M=2e6+10;
struct node1{
	int u,v,w,id;
}e1[M],e2[M],e3[M];
int n,m,k,mm=0;
int a[12][N],c[12];
int fa[N];
bool vis[M],visb[12];
ll ans=0,res=0;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruskal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=e1[i].u,v=e1[i].v;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			vis[i]=1;
			ans+=e1[i].w;
		}
	}
	return ;
}
void kruskal2(int iid){
	for(int i=1;i<=n+iid;i++) fa[i]=i;
	for(int i=1;i<=mm;i++){
		int u=e1[i].u,v=e1[i].v;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			vis[i]=1;
			res+=e1[i].w;
		}
	}
	for(int i=1;i<=mm;i++){
		if(vis[i]) visb[e1[i].id]=1;
	}
	return ;
}
bool cmp(node1 aa,node1 bb){
	if(aa.w==bb.w) return aa.id<bb.id;
	return aa.w<bb.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	mm=m;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e1[i]={u,v,w,0};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	sort(e1+1,e1+m+1,cmp);
	kruskal();
	for(int i=1;i<=k;i++){
		res=0;
		memset(visb,false,sizeof visb);
		memset(vis,false,sizeof vis);
		int tt=mm;
		for(int j=1;j<=tt;j++) e3[j]=e1[j];
		for(int j=1;j<=n;j++) e1[++mm]={n+i,j,a[i][j],i};
		sort(e1+1,e1+mm+1,cmp);
		kruskal2(i);
		for(int j=1;j<=i;j++){
			if(visb[j]) res+=c[j]; 
		}
		if(ans<=res){
			for(int j=1;j<=mm;j++) e1[j]={0,0,0,0}; 
			for(int j=1;j<=tt;j++) e1[j]=e3[j];
			mm=tt;
		}else ans=res;
	}
	cout<<ans;
	return 0;
}
