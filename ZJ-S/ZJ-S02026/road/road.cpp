#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
struct node{
	int u,v,w;
	bool operator< (const node &a)const{
		return w>a.w;
	}
};
priority_queue<node> q;
int n,m,k,build[N],ans,fa[N];
signed G[N][N]; // w is the edge
int f(int x){
	if(fa[x]==x) return x;
	return fa[x]=f(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(G,0x3f,sizeof(G));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		G[u][v]=G[v][u]=min(G[u][v],(signed)w);
	}
	for(int l=1;l<=k;l++){
		int bas; cin>>bas;
		for(int i=1;i<=n;i++){
			cin>>build[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				G[i][j]=min(G[i][j],(signed)(bas+build[i]+build[j]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			q.push(node{i,j,G[i][j]});
		}
	}
	int cnt=0;
	while(q.size()){
		node fr=q.top();
		int fu=f(fr.u),fv=f(fr.v);
		if(fu!=fv){
			fa[fu]=fv;
			cnt++;
			ans+=G[fr.u][fr.v];
		}
		q.pop();
	}
	cout<<ans;
	return 0;
}
