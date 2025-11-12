#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=10105,M=2000005+200005;
int cnt;
int c[15],cr[15][N];
struct point{
	int v,w,u;
}e[M];
bool cmp(point &x,point &y){
	return x.w<y.w;
}
void addedge(int u,int v,int w){
	e[++cnt].v=v,e[cnt].w=w,e[cnt].u=u;
}
int f[N];
int find(int x){
	if(x==f[x])return x;
	else return f[x]=find(f[x]);
}
bool vis[N];
int ans=0,ans2=0x3f3f3f3f;
void mst(int t){
	for(int i=1;i<=n+t;i++)f[i]=i;
	sort(e+1,e+cnt+1,cmp);
	int tot=0;
	for(int i=1;i<=cnt && tot<n;i++){
		if((!e[i].u) || (!e[i].v))continue; 
		if(find(e[i].u)!=find(e[i].v)){
			f[find(e[i].u)]=find(e[i].v);
			ans+=e[i].w;
			tot++;
		}
	}
}
bool flag[N];
void dfs(int x,int sum,int t){
	if(x>k)return;
	ans=sum;
	mst(t);
	ans2=min(ans2,ans);
	dfs(x+1,sum,t);
	ans=sum+c[x];
	flag[x]=1;
	mst(t+1);
	ans2=min(ans2,ans);
	dfs(x+1,sum+c[x],t+1);
	flag[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&cr[i][j]);
			addedge(n+i,j,cr[i][j]);
			addedge(j,n+i,cr[i][j]);
		}
	}
	for(int i=1;i<=n;i++)flag[i]=1;
	if(!k){
		mst(0);
		ans2=min(ans2,ans);
	}
	dfs(1,0,0);
	cout<<ans;
}
