#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int from,to,w,nxt;
}edge[2000005];
long long n,m,k,x,y,z,edgenum,head[10005],a[15],b[15],g[15][10005],fa[10055],du[10055],e[10055],ans;
void add(int from,int to,long long w){
	edge[++edgenum].from=from;
	edge[edgenum].to=to;
	edge[edgenum].w=w;
	edge[edgenum].nxt=head[from];
	head[from]=edgenum;
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
long long kruskal(int num){
	long long sum=0;
	sort(edge+1,edge+edgenum+1,cmp);
	for(int i=1;i<=num;i++)
		fa[i]=i;
	for(int i=1;i<=edgenum;i++){
		int fx=find(edge[i].from),fy=find(edge[i].to);
		if(fx!=fy)
			fa[fx]=fy,sum+=edge[i].w,du[edge[i].from]++,du[edge[i].to]++,e[edge[i].to]=edge[i].w,e[edge[i].from]=edge[i].w;
	}
	for(int i=1;i<=k;i++)
		if(du[i+n]<=1)
			sum-=e[i+n];
	return sum;
}
//void dfs(int x,int d,int len){
//	if(d==len)
//	for(int j=x+1;j<=k;j++){
//		dfs(j,d++,i);
//	}
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>x>>y>>z,add(x,y,z);
	if(k==0){
		cout<<kruskal(n);
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		for(int j=1;j<=n;j++)
			cin>>x,g[i][j]=x;
	}
//	ans=max(ans,kruskal(n));
//	for(int i=1;i<=k;i++)
//		dfs(0,0,i);
	if(b[k]==0){
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				add(i+n,j,g[i][j]);
		cout<<kruskal(n+k);
		return 0;
	}
	return 0;
}
