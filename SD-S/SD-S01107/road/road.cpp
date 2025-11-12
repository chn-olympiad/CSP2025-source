#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
vector< pair<int,int> >q[10020];
priority_queue<pair<int,int> >h;
long long ans=0;
int f[10020];
bool vis[10020];
int cnt=0;
int kc[10005];
//int find(int x){
//	return f[x]==x ? x : f[x]=find(f[x]);
//}
//void un(int x,int y){
//	int po=find(x),oq=find(y);
//	if(po!=oq){
//		fa[oq]=po;
//	}
//	return ;
//}
void dji(int x){
	vis[x]=1;
	for(int i=0;i<q[x].size();i++){
		h.push({-q[x][i].second,q[x][i].first});
	}
	while(!h.empty()){
		int w=-h.top().first,id=h.top().second;
		
		
		h.pop();
		if(vis[id]==1)continue;
		printf("%d %d\n",w,id);
		vis[id]=1;
		ans+=w;
		for(int i=0;i<q[id].size();i++){
			if(vis[q[id][i].first]==0){
				
				h.push({-q[id][i].second,q[id][i].first});
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		q[u].push_back({v,w});
		q[v].push_back({u,w});
	}
	int c;
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&kc[j]);
		}
		for(int j=1;j<=n;j++){
			for(int e=1;e<=n;e++){
				if(j==k)continue;
				q[j].push_back({e,kc[j]+kc[e]});
				q[e].push_back({j,kc[j]+kc[e]});
			}
		}
	}
	dji(1);
	printf("%lld",ans);
	return 0;
}
