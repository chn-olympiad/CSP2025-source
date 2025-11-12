#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
const int N=1e4+10;
int n,m,k;
struct A{
	int to,w;
};
vector <A> G[N];
int arr[20][N]; 
int dis[N];
struct B{
	int idx,d;
	bool operator < (const B &rhs) const{
	    return d>rhs.d;
	}
};
priority_queue<B> pq;
bool vis[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1,u,v,w;i<=m;i++){
    	scanf("%lld%lld%lld",&u,&v,&w);
    	G[u].push_back({v,w});
    	G[v].push_back({u,w});
	}
	for (int i=1;i<=k;i++){
		cin >> arr[i][0];
		for (int j=1;j<=n;j++){
			scanf("%lld",&arr[i][j]);
			//cin >> arr[i][j];
		}
	} 
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;vis[1]=1;
	for (int i=0;i<G[1].size();i++){
		int to=G[1][i].to,w=G[1][i].w;
		
		//cout << to << ' ' << w << endl;
		dis[to]=min(dis[to],w);
		pq.push({to,dis[to]});
	}
	for (int i=2;i<=n;i++){
		int to=i,w=0x3f3f3f3f3f3f3f3f;
		for (int j=1;j<=k;j++){
			w=min(w,arr[j][0]+arr[j][1]+arr[j][i]);
		}
		dis[to]=min(dis[to],w);
		pq.push({to,dis[to]});
	}
	int ans=0;
	while(!pq.empty()){
		int x=pq.top().idx,d=pq.top().d;pq.pop();
		if (dis[x]<d) continue;
		//cout << x << ' ' << dis[x] << endl;
		ans+=dis[x];
		dis[x]=0;vis[x]=1;
		for (int i=0;i<G[x].size();i++){
			int to=G[x][i].to,w=G[x][i].w;
			//if (vis[to]) continue;
			if (w<dis[to]){
				dis[to]=w;
				pq.push({to,w});
			}
		} 
		for (int i=1;i<=n;i++){
			
			int to=i,w=0x3f3f3f3f3f3f3f3f;
			//if (vis[to]) continue;
			for (int j=1;j<=k;j++){
				w=min(w,arr[j][0]+arr[j][x]+arr[j][to]);
			}
			if (w<dis[to]){
				dis[to]=w;
				pq.push({to,w});
			}
		}
	}
	cout << ans;
	

	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
