#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
const int N=1e4+10,M=1e6+10,K=15;
struct Edge{
	int x,y,w;
}e[M];
int c[K],a[K][N];
vector<PII> v[N];
int prim(int x){
	priority_queue<PII,vector<PII>,greater<PII> > heap;
	int dist[N];
	bool vis[N];
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	dist[x]=0;
	heap.push({dist[x],x});
	int ans=0;
	while(!heap.empty()){
		int top=heap.top().y;
		heap.pop();
		if(vis[top]) continue;
		vis[top]=1;
		ans+=dist[top];
		for(int i=0;i<v[top].size();i++){
			int k1=v[top][i].x,k2=v[top][i].y;
			if(dist[k1]>k2){
				dist[k1]=k2;
				heap.push({dist[k1],k1});
			}
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		e[i].x=x,e[i].y=y,e[i].w=w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	if(k==0){
		int ans=prim(1);
		cout<<ans<<"\n";
		return 0;
	}
	bool f=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		if(c[i]){
			f=0;
		}
	}
	if(f){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int ij=1;ij<=n;ij++){
					if(j!=ij){
						v[j].push_back({ij,a[i][j]+a[i][ij]});
						v[ij].push_back({j,a[i][j]+a[i][ij]});
					}
				}
			}
		}
		int ans=prim(1);
		cout<<ans<<"\n";
		return 0;
	}
	cout<<0<<"\n";
	return 0;
}
