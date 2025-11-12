#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e4+5,M=6e7+5,INF=2e9;
struct node{
	int u,v,w;
	friend bool operator <(node x,node y){
		return x.w<y.w;
	}
}t[M];
bool f[N][N];
ll ans,g[N][N];
int n,m,k,c[N],a[15][N],fa[N];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	} 
}
int find(int x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
void uni(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
void find_mst(){
	int cnt=0;
	init();
	sort(t+1,t+m+1);
	for(int i=1;i<=m;i++){
		if(find(t[i].u)!=find(t[i].v)){
			ans+=t[i].w,cnt++;
			uni(t[i].u,t[i].v);
			if(cnt==n-1){
				break;
			}
		}
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=INF;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>t[i].u>>t[i].v>>t[i].w;
		g[t[i].u][t[i].v]=t[i].w,g[t[i].v][t[i].u]=t[i].w;
		f[t[i].u][t[i].v]=1,f[t[i].v][t[i].u]=1;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i]; 
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int x=1;x<=n;x++){
			for(int y=i+1;y<=n;y++){
				g[x][y]=min(g[x][y],(ll)a[i][x]+a[i][y]+c[i]),g[y][x]=g[x][y];
				f[x][y]=1,f[y][x]=1;
			}
		}
	}
	if(k){
		m=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f[i][j]){
					t[++m]={i,j,(ll)g[i][j]};
				}
			}
		}
	}
	find_mst();
	cout<<ans;
	return 0;
}
