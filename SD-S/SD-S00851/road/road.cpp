#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e4+10,M=1e6+10,K=11;
struct Node{
	int u,v,w;
}T[M+N];
int f[N+K*2],flg[N+K*2],c[N+K*2],a[K][N];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void join(int x,int y){
	x=find(x),y=find(y);
	f[x]=y;
}
bool query(int x,int y){
	return (find(x)==find(y));
}
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int kruskal(int n,int m,int op){
	int e=0,sum=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m&&e<n-1-op;i++){
		int u=T[i].u,v=T[i].v,w=T[i].w;
		if(flg[u]||flg[v]) continue;
		if(!query(u,v)){
			join(u,v);
			e++,sum+=w;
		}
	}
	if(e<n-1-op) return 1e18;
	return sum;
}
int n,m,k,vis[K],mn=1e18,Flg[N],Cnt[N];
void dfs(int p){
	if(p>k){
		int op=0;
		for(int i=1;i<=k;i++){
			if(vis[i])
				flg[i+n]=1,flg[i+n+k]=1,op+=2;
		}
		int p=kruskal(n+2*k,m,op);
		mn=min(mn,p);
		for(int i=1;i<=k;i++)
			flg[i+n]=0,flg[i+n+k]=0;
		return;
	}
	vis[p]=1,dfs(p+1);
	if(Flg[p]==0) vis[p]=0,dfs(p+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int mx=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		T[i]={u,v,w};
		mx=max(mx,w);
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++)
			cin>>a[j][i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(mx<a[i][j]) continue;
			Cnt[i]++;
			T[++m]={i+n,j,a[i][j]};
		}	
	}
	for(int i=1;i<=k;i++){
		if(Cnt[i]<2){
			Flg[i]=1;
			continue;
		}
		if(mx<c[i]){
			Flg[i]=1;
			continue;
		}
		T[++m]={i+n+k,n+i,c[i]};
	}
	sort(T+1,T+m+1,cmp);
	dfs(1);
	cout<<mn;
	return 0;
}
//CSP-S2025 rp++
//[64,100]
