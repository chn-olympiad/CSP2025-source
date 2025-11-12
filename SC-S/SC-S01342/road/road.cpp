#include<bits/stdc++.h>
using namespace std;

const long long N = 1e4+105,INF = 0x3f3f3f3f;
long long i,j,k,l,n,m,a[N][N],b[N],x,y; 

struct E{
	long long to,w;
};

vector<E> adj[N];
long long cnt[N],wi[N];

void lian(int s){
	queue<long long> pq;
	fill(wi,wi+n+k,-1);
	wi[1] = 0;
	pq.push(1);
	while(pq.size()){
		int u = pq.front();
		pq.pop();
		
		for(int i = 0;i < adj[u].size();i ++){
			int v = adj[u][i].to , w = adj[u][i].w;
			if(wi[v] == -1){
				wi[v] = w;
				pq.push(v);
			}else if(wi[v] > w){
				wi[v] = w; 
			}
		}
	}
	
}

priority_queue<pair<long long,long long>,vector<pair<long long,long long> > ,greater<pair<long long,long long> > > pq;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(i = 1;i <= m;i ++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	lian(1);
	long long ans = 0;
	for(i = 1;i <= k;i ++){
		cin >> b[i];
		for(j = 1;j <= n;j ++){
			cin >> a[i][j];
		}
	}
	if(k == 0){
		for(i = 1;i <= n;i ++){
			ans += wi[i];
		} 
		cout << ans;
		return 0;
	}
	
	
	for(i = 1;i <= k;i ++){
		while(pq.size())pq.pop();
		for(j = 1;j <= n;j ++){
			pq.push({a[i][j],j});
		}
		long long len;
		for(j = 1;j <= n;j ++){
			if(pq.top().second == j){
				pq.pop();
				len = b[i] + a[i][j] + pq.top().first;
				pq.push({a[i][j],j});
			}
			else{
				len = b[i] + a[i][j] + pq.top().first;
			}
			if(len < wi[j]){
				cnt[i] ++;
				wi[j] = len;
			}
		}
	}
	for(i = 1;i <= n;i ++){
		ans += wi[i];
	}
	for(i = 1;i <= k;i ++){
		if(cnt[i] > 1)ans -= b[i]*(cnt[i]-1);
	}
	cout << ans;
	return 0;
}