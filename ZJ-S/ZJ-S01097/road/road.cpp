#include<bits/stdc++.h>
#define ll long long 
const int M=1e6+5;
const int N=1e4+5;
struct e{
	int to;
	int next;
	ll w;
}edge[M*10];
int head[N],cnt;
void add_edge(int u,int v,ll w){
	edge[++cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
struct node{
	ll dis;
	int idx;
	bool operator<(const node &x)const {
		return dis>x.dis;
	}
};
int n,m,k;
ll c[15][N+5];
ll ans;
ll dis[N];
bool vis[N];
ll prim(){
	std::priority_queue<node> pq;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	pq.push({0,1});
	dis[1]=0;
	int num=0;
	ll ans=0;
	while(!pq.empty()){
		int idx=pq.top().idx;
		ll val=pq.top().dis;
		pq.pop();
		if(vis[idx]){
			continue;
		}
		vis[idx]=true;
		ans+=dis[idx];
		for(int i=head[idx];i;i=edge[i].next){
			if(!vis[edge[i].to]&&dis[edge[i].to]>edge[i].w){
				dis[edge[i].to]=edge[i].w;
				pq.push({dis[edge[i].to],edge[i].to});
			}
		}
	}
	return ans;
}
void solve_1(){
	printf("%lld\n",prim());
}



int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<=m;i++){
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	bool check=false;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&c[i][j]);
			if(c[i][j]!=0){
				check=true;
			}
		}
	}
	if(k==0){
		solve_1();
	}else if (!check){
		printf("0\n");
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll minn=0x3f3f3f3f3f3f3f3f;
				for(int l=1;l<=k;l++){
					minn=std::min(minn,c[l][0]+c[l][i]+c[l][j]);
				}
				add_edge(i,j,minn);
				add_edge(j,i,minn);
			}
		}
		printf("%lld",prim());
	}
	
	
	
	
	return 0;
}
/*
3 5 0
1 2 5
2 3 6
1 3 1
3 4 1
2 4 10
*/
