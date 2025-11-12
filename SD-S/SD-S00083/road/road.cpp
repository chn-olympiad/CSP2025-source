#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
vector<int>nxt[N],va[N];
long long dist[N];
bool vis[N];
long long ans[N];
void dijikstra(int s){
	
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
	for(int i=1;i<=n;i++){
		dist[i]=1e9;
	}
	dist[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		pair<long long,long long> now=q.top();
		q.pop();
		int o=now.second;
		if(vis[o]){
			continue;
		}
		vis[o]=1;
		for(int i=0;i<nxt[o].size();i++){
			if(now.first+va[o][i]<dist[nxt[o][i]]){
				dist[nxt[o][i]]=now.first+va[o][i];
				ans[nxt[o][i]]=va[o][i];
				q.push(make_pair(dist[nxt[o][i]],nxt[o][i]));
			}
		}
	}
}
void add(int u,int v,int w){
	nxt[u].push_back(v);
	va[u].push_back(w);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,len;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>len;
		add(u,v,len);
		add(v,u,len);
	}
	int c;
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&u);
			
		}
	}
//	for(int i=1;i<=n;i++){
		dijikstra(1);
//	}
	long long sa=0;
	for(int i=1;i<=n;i++){
		sa+=ans[i];
	}
	cout<<sa;
	return 0;
}
