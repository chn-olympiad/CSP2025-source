#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10,K=20,inf=-0x3F3F3F3F;
int n,m,k,cnt=0,a[K][N],c[K];
struct EDGE{
	int from,to,w,next;
}edge[M];
int head[N];
void init(){
	for(int i=1;i<=n;i++)head[i]=-1;
	for(int i=1;i<=m;i++)edge[i].next=-1;
}
void add_edge(int u,int v,int w){
	edge[++cnt]={u,v,w,head[u]};
	head[u]=cnt;
}
int main(){
	//freopen("road1.in","r",stdin);
	//freopen("road1.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	return 0;
}