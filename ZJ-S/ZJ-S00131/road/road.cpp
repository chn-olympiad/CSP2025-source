#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+16;
const int maxm=1e6+14;
int n,m,k,cnt=1,ans;
int town[11],dis[maxn];
vector< pair<int,int> >road[maxn];

void Dij(){
	priority_queue<int>q;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push(1);
	while(q.size()!=0){
		int tar=q.top();q.pop();
		for(int i=0;i<road[tar].size();i++){
			int v=road[tar][i].first;
			int w=road[tar][i].second;
			if(dis[v]>dis[tar]+w){
				dis[v]=dis[tar]+w;
				q.push(v);
			}
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	while(m--){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		road[u].push_back(make_pair(v,w));
		road[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&town[i]);
		for(int j=1;j<=n;j++){
			int w;scanf("%lld",&w);
			road[n+i].push_back(make_pair(j,w));
			road[j].push_back(make_pair(n+i,w));
		}
	}
	Dij();
	for(int i=1;i<=n;i++) ans+=dis[i];
	printf("%lld\n",ans);
	return 0;
}
