#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 10050
#define M 2000050
typedef long long ll;
typedef pair<ll,ll> pii;
#define int long long

int n,m,k;
struct edge{
	int from,to,nxt;
	ll val;
	friend bool operator <(edge a,edge b){
		return a.val<b.val;
	}
}e[M];
int h[N],tot=0,fa[N];
ll c[20],a[20][N],ans=0;
void add(int u,int v,int w){
	e[++tot]=(edge){u,v,h[u],w};
	h[u]=tot;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void kruskal(){
	sort(e+1,e+tot+1);
	for(int i=1; i<=tot; i++){
		int u=find(e[i].from);
		int v=find(e[i].to);
		if(u==v) continue;
		
		ll minn=e[i].val,minj=0;
		for(int j=1; j<=k; j++){
			if(a[j][u]+a[j][v]+c[j]<=minn){
				minn=a[j][u]+a[j][v]+c[j];
				minj=j;	
			}
		}
		if(minj!=0){
			ans+=minn;
			a[minj][u]=a[minj][v]=0;
			c[minj]=0;
		}else{
			ans+=e[i].val;
		}
		
		for(int j=1; j<=k; j++)
			a[j][u]=min(a[j][u],a[j][v]);
		fa[v]=u;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1,u,v,w; i<=m; i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	}
	kruskal();
	cout<<ans;
	return 0;
}
