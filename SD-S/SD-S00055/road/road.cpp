#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
int n,m,k,c[15],a[15][N];
struct node{
	int v,w;
};
vector<node> edge[N];
bool vis[N];
ll dis[N],res,ans;
void djisktra(){
	vis[1]=1;
	queue<int> q;
	q.push(1);
	memset(dis,0x7f,sizeof dis);
	dis[1]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int t[N],cnt=0;
		ll minn=1e18+5;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].v;
			if(vis[v]) continue;
			int w=edge[u][i].w;
			if(dis[v]>=dis[u]+w){
				if(dis[v]<1e18){
					res+=dis[v];
				}
				dis[v]=dis[u]+w;
			}
			if(dis[v]<minn){
				minn=dis[v];
				cnt=0;
				t[++cnt]=v;
			}else if(dis[v]==minn) t[++cnt]=v;
		}
		for(int i=1;i<=cnt;i++){
			q.push(t[i]);
			vis[t[i]]=1;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
		ans+=w;
	}
	djisktra();
	bool f=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) f=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]) f=0;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	cout<<ans-res;
	return 0;
}


