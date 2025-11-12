#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1.5e6+5;
const int K=15;
int n,m,k,c[K],a[K][N],fa[N],cnt,ans,ans1=INT_MAX,bian;
bool vis[N];
struct node{int u,v,w;}e[M],e1[M];
bool cmp(node x,node y){return x.w<y.w;}
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y,int w){
	x=find(x),y=find(y);
	if(y!=x) fa[y]=x,ans+=w,cnt++;
}
void kruskal(){
	sort(e+1,e+bian+1,cmp);cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=bian;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		unionn(u,v,w);
		if(cnt==n-1) break;
	}
}
void work(){
	bian=m;
	for(int i=1;i<=K;i++){
		if(!vis[i]) continue;
		for(int j=1;j<=n;j++)
			for(int l=1;l<j;l++)
				e[++bian]={j,l,a[i][j]+a[i][l]};
	}
	for(int i=1;i<=bian;i++) e1[i]=e[i];
	kruskal();
	for(int i=1;i<=m;i++) e[i]=e1[i];
	ans1=min(ans1,ans);
}
void dfs(int i,int sum){
	if(i==k+1){
		ans=sum;work();
		return ;
	}
	vis[i]=1;dfs(i+1,sum+c[i]);
	vis[i]=0;dfs(i+1,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);bian=m;
	for(int i=1,u,v,w;i<=m;i++){
	    scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};	
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	if(k==0){
		kruskal();printf("%d",ans);
		return 0;
	}
	dfs(1,0);printf("%d",ans1);
	return 0;
}

