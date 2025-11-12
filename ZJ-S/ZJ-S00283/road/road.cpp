#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e4+50+5,M=2e6+5;
int n,m,k,u,v,w,c[15],a[15][N],
	fa[N],cnt,t,num,mark[N];
ll sum;
struct edge{
	int x,y,w;
	bool operator<(const edge &g) const{return w<g.w;}
}e[M],ne[M];
struct node{
	int to,w;
};
int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
vector<int> G[N];
void tree(){
	for(int i=1;i<=cnt;i++) ne[i]=e[i];
	sort(ne+1,ne+cnt+1);
	sum=0;t=0;
	num++;
	for(int i=1;i<=n+k+1;i++)
		fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int u=ne[i].x,v=ne[i].y,w=ne[i].w;
		int x=Find(u),y=Find(v);
		if(x==y) continue;
		t++;
		if(t==num) break;
		fa[x]=y;
		sum+=w;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[i]=edge{u,v,w};
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		e[++cnt]=edge{n+k+1,n+i,c[i]};
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			e[++cnt]=edge{n+i,j,a[i][j]};
		}
	}
	num=n+k;
	tree();
	cnt=m;
	num=n;
	for(int i=1;i<=k;i++){
		int flag=0;
		for(auto x:G[n+i]){
			if(x==n+k+1) flag=1;
		}
		mark[n+i]=1;
		if(flag==1){
			num++;mark[n+i]=0;
			e[++cnt]=edge{n+k+1,n+i,c[i]};
			for(int j=1;j<=n;j++){
				e[++cnt]=edge{n+i,j,a[i][j]};
			}
		}
	}
	tree();
	printf("%lld",sum);
	return 0;
}
