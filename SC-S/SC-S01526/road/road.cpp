#include<bits/stdc++.h>
using namespace std;
const int N=1e4+26,M=1e6+26,K=16,INF=2e9+66;
int n,m,k,used[N],vis[N],from[N],cnt[N];
long long dis[N],c[N],ans;
struct node{
	long long weight,to;
};
vector<node>edge[N];
struct data{
	long long val,id;
	bool operator < (data other)const{
		return val>other.val;
	}
};
priority_queue<data>pq;
void dij(){
	for(int i=1;i<=n+k;i++)dis[i]=INF;
	dis[1]=0;
	pq.push({dis[1],1});
	while(!pq.empty()){
		int v=0;
		v=pq.top().id;
		dis[v]=pq.top().val;
		used[v]=1;
		if(v==0)break;
		for(auto u:edge[v]){
			long long tt=dis[v]+u.weight;
			if(u.to>n&&vis[u.to]==0){
				tt+=c[u.to];
				vis[u.to]=1;
			}
			if(dis[u.to]>tt){
				from[u.to]=v;
				dis[u.to]=tt;
				pq.push({tt,u.to});
			}else if(dis[from[u.to]]==tt){
				if(dis[v]>dis[from[u.to]])from[u.to]=v;
			}
		}
		while((!pq.empty())&&used[pq.top().id]==1){
			pq.pop();
		}
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		long long iu,iw,iv;
		scanf("%lld%lld%lld",&iu,&iv,&iw);
		edge[iu].push_back({iw,iv});
		edge[iv].push_back({iw,iu});
	}
	for(int i=n+1;i<=n+k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			long long ic;
			scanf("%lld",&ic);
			edge[i].push_back({ic,j});
			edge[j].push_back({ic,i});
		}			
	}
	dij();
	for(int i=2;i<=n;i++){
		if(cnt[i]==0){
			ans+=dis[i];
			int p=i;
			while(p!=1){
				cnt[p]=1;
				p=from[p];
			}
		}				
	}
	printf("%lld",ans);
	return 0;
} 