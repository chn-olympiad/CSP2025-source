#include <bits/stdc++.h>
using namespace std;
const int N=1e4+7;
typedef long long ll;
int n,m,k;
int u,v,w;
struct Node {
	int v,cost;
} ;
vector <Node> road[N];
bool vis[N]={0};
ll ans;

bool cmp(Node x,Node y){
	return x.cost<y.cost;
}

void bfs(int x){
//	memset(tmp,0,sizeof(tmp));
	Node tmp[N];
	int idx=0;
	
	for(Node i : road[x]){
		idx++;
		tmp[idx].v=i.v;
		tmp[idx].cost=i.cost;	
	}
	
	sort(tmp+1,tmp+idx+1,cmp);
	
	for(int i=1;i<=idx;i++){
		if(vis[tmp[i].v]) continue;
		vis[tmp[i].v]=true;
		ans+=tmp[i].cost;
		bfs(tmp[i].v);
	}
	
	return;
}

int main(){
	
	freopen("road.in","r",stdin);//Òª¸Ä 
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		road[u].push_back({v,w});
		road[v].push_back({u,w});
	}
	vis[1]=true;
	bfs(1);
	
	cout<<ans<<endl;
	return 0;
} 
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/ 
