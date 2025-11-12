#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;

int n,m,k;
ll ans=LLONG_MAX;
struct EDGE{
	int u,v,val;
	bool operator <(const EDGE b)const{return b.val<val;}
};
int u[M],v[M],w[M];
int c[20],kk[20][N];
priority_queue<EDGE> pq;
vector<int> g[N];
bool vis[20];


struct EDU{
	int fa[N];
	void init(){for(int i=1;i<=N;i++)fa[i]=i;}
	int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
	void merge(int u,int v){fa[find(u)]=find(v);}
	bool check(int u,int v){return find(u)==find(v);}
}edu;


void dfs(int now){
	if(now>k){
		edu.init();
		ll sum=0;
		for(int i=1;i<=m;i++)pq.push({u[i],v[i],w[i]});
		for(int i=1;i<=k;i++){
			if(vis[i]){
				sum+=c[i];
				for(int j=1;j<=n;j++)pq.push({n+i,j,kk[i][j]});
			}
		}
		while(!pq.empty()){
			EDGE tmp=pq.top();pq.pop();
			int u=tmp.u,v=tmp.v,w=tmp.val;
			if(!edu.check(u,v))edu.merge(u,v),sum+=w;
		}
		ans=min(ans,sum);
//		printf("%lld\n",sum);
		return ;	
	}
	vis[now]=0,dfs(now+1);
	vis[now]=1,dfs(now+1);
	
	return ;
}

void SOLVE(){
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	
	bool flagA=1;
	for(int i=1;i<=k;i++){
		bool cnt0=0;
		scanf("%d",&c[i]);
		if(c[i]!=0)flagA=0;
		for(int j=1;j<=n;j++){scanf("%d",&kk[i][j]);if(kk[i][j]==0)cnt0=1;}
		flagA=cnt0;
	}
	if(flagA){
		ll sum=0;
		edu.init();
		for(int i=1;i<=m;i++)pq.push({u[i],v[i],w[i]});
		for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)pq.push({n+i,j,kk[i][j]});
		while(!pq.empty()){
			EDGE tmp=pq.top();pq.pop();
			int u=tmp.u,v=tmp.v,w=tmp.val;
			if(!edu.check(u,v))edu.merge(u,v),sum+=w;
		}
		printf("%lld\n",sum);
		return ;
	}
//	if(n<=1005){
//		edu.init();
//		int sum=0;
//		for(int i=1;i<=m;i++)pq.push({u[i],v[i],w[i]});
//		for(int i=1;i<=k;i++)for(int u=1;u<=n;u++)for(int v=i+1;v<=n;v++)pq.push({u,v,kk[i][u]+kk[i][v]+c[i]});
//		while(!pq.empty()){
//			EDGE tmp=pq.top();pq.pop();
//			int u=tmp.u,v=tmp.v,w=tmp.val;
//			if(!edu.check(u,v))edu.merge(u,v),sum+=w;
//		}
//		printf("%lld\n",sum);
//		return ;
//	}
	dfs(1);
	printf("%lld\n",ans);
	return ;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int Test_time=1;
//	scanf("%d",&Test_time);
	while(Test_time--)SOLVE();
	return 0;
}
/*
15:40 20min guo qu le, wo hao wu tou xu
15:45 I got a O(km)'s method it's too slow
16:15 No any progress,O(km) only can get 72 points
17:15 hao ba,OK I think 72 points is enough 		qwq	
*/
