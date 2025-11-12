#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 7;
const int MAXM = 2e6 + 7;
const int MAXK = 1e1 + 7;
const long long INF = 1e14 + 7;

struct Edge{
	int to;
	int nxt;
	long long wgt;
}edge[MAXM << 1];
int head[MAXN],cnt = 0;

void addedge(int u,int v,long long w){
	edge[cnt].to = v;
	edge[cnt].wgt = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt++;
}

int count_tree_edge = 0;
int tot_node;
long long dis[MAXN];
bool vis[MAXN];
long long Prim(int start){
	dis[start] = 0;
	vis[start] = true;
	long long ans = 0;
	int now = start;
	long long min_dis = INF;
	for(int i = head[now];i != -1;i = edge[i].nxt){
		if(dis[edge[i].to] > edge[i].wgt){
			dis[edge[i].to] = edge[i].wgt;
		}
	}
	
	while(count_tree_edge < tot_node - 1){
		//find nearest node(priority_queue?)
			//check all:
		min_dis = INF;
		for(int i = 1;i <= tot_node;i++){
			if(!vis[i] && dis[i] < min_dis){
				now = i;
				min_dis = dis[i];
			}
		}
		
		//join the node to the tree		
		ans += min_dis;
		vis[now] = true;
		count_tree_edge += 1;
		
		//update the dis[] and vis[]
		for(int i = head[now];i != -1;i = edge[i].nxt){
			if(!vis[edge[i].to] && dis[edge[i].to] > edge[i].wgt){
				dis[edge[i].to] = edge[i].wgt;
			}
		}
	}
	return ans;
}

void init(){
	for(int i = 0;i < (MAXM << 1);i++){
		edge[i].nxt = -1;
	}
	for(int i = 0;i < MAXN;i++){
		head[i] = -1;
		dis[i] = INF;
		vis[i] = false;
	}
	cnt = 0;
}

int n,m,k;
long long c[MAXK];
long long a[MAXK][MAXN];
int main(){
	//target score:12 * 4' = 48'(k = 0 or c[j] = 0)
	//forgot the ues of STL:priority_queue...
	//predict:10e4 cannot accept
	//10e3 * 6 -> score might be 24'
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	init();
	scanf("%d%d%d",&n,&m,&k);
	tot_node = n + k;
	for(int i = 1;i <= m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i = 1;i <= k;i++){
		scanf("%lld",&c[i]);
		for(int j = 1;j <= n;j++){
			scanf("%lld",&a[i][j]);
			addedge(n + i,j,a[i][j]);
			addedge(j,n + i,a[i][j]);
		}
	}
	long long ans = Prim(1);
	printf("%lld",ans);
	return 0;
}
