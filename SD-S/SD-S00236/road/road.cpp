#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int NN=6e6+10;
const int INF=1e18;
int st;
struct node{
	int u,v,w;
};
node b[NN];
bool cmp(node x,node y){
	return x.w<y.w;
}
int cnt=0;
int f[N];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int n,m,k;
int op[NN];
int ed;
int ksl(int nx){
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	int ans=0;
	int sm=0;
	for(int i=1;i<=cnt;i++){
		int u=b[i].u,v=b[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv){
			continue;
		}
		if(!op[u]||!op[v]){
			continue;
		}
		sm++;
		f[fu]=fv;
		ans+=b[i].w;
	}
	if(sm!=n+nx-1){
		return -1;
	}
	return ans;
}
int kc[N];
void soa(){
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	sort(b+1,b+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int u=b[i].u,v=b[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv){
			continue;
		}
		f[fu]=fv;
		ans+=b[i].w;
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		op[i]=1;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		b[++cnt]={u,v,w};
	}
	int allz=0;
	for(int i=1;i<=k;i++){
		cin>>kc[i];
		allz+=kc[i];
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			b[++cnt]={i+n,j,x};
		}
	}
	if(allz==0){
		soa();
		return 0;
	}
	sort(b+1,b+cnt+1,cmp);
	int ans=INF;
	for(int K=0;K<(1<<k);K++){
		int sm=0;
		int kv=0;
		for(int i=0;i<k;i++){
			if((K>>i)&1){
				kv+=kc[i+1];
				op[i+n+1]=1;
				sm++;
//				cout<<1<<" ";
			}
			else{
				op[i+n+1]=0;
//				cout<<0<<" ";
			}
		}
//		cout<<endl;
		int nas=ksl(sm);
//		cout<<nas+kv<<endl;
		if(nas!=-1){
			ans=min(ans,nas+kv);
		}
	}
	cout<<ans;
	return 0;
}


//int prim(int s){
//	for(int i=0;i<=NN-10;i++){
//		dis[i]=INF;vis[i]=0;
//	}
//	priority_queue<Node> q;
//	q.push({s,0});
//	dis[s]=0;
//	int ans=0;
//	while(!q.empty()){
//		int u=q.top().v;
//		q.pop();
//		if(vis[u]){
//			continue;
//		}
//		vis[u]=1;
//		for(int i=0;i<g[u].size();i++){
//			int v=g[u][i].v;
//			int w=g[u][i].w;
//			if(cn[v]){
//				if(!op[v]){
//					continue;
//				}
//			}
//			if(dis[v]>dis[u]+w){
////				cout<<u<<" "<<v<<" "<<w<<endl;
//				if(dis[v]==INF){
//					ans+=w;
//				}
//				else{
//					ans+=dis[v]-dis[u]-w;
//				}
//				dis[v]=dis[u]+w;
//				q.push({v,dis[v]});
//			}
//		}
//	}
//	return ans;
//}
