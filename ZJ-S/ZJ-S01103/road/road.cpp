#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
int n,m,k,c,u,v,w,a[1005][1005],t[1005];
vector<pair<int,int> > pc[10005]; 
bool vis[10005];
priority_queue<pair<int,int> ,vector<pair<int,int> > , greater<pair<int,int> > > pq;
void krus1(){
	int cnt=0;
	long long ans=0;
	pq.push(mp(0,1));
	while(!pq.empty()){
		int d=pq.top().first,now=pq.top().second; 
		pq.pop();if(vis[now]) continue;ans+=d;vis[now]=1;
		cnt++;if(cnt==n) break;
		for(int i=0;i<pc[now].size();i++){
			int to=pc[now][i].second;
			if(!vis[to]){
				pq.push(mp(pc[now][i].first,to));
			}
		}
	}cout<<ans;
}
void krus2(){
	int cnt=0;
	long long ans=0;
	pq.push(mp(0,1));
	while(!pq.empty()){
		
		int d=pq.top().first,now=pq.top().second; 
		pq.pop();if(vis[now]) continue;ans+=d;vis[now]=1;
		cnt++;if(cnt==n) break;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&a[now][i]!=0x3f3f3f3f) pq.push(mp(a[now][i],i));
		}
	}cout<<ans;	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			pc[u].pb(mp(w,v));
			pc[v].pb(mp(w,u));
		}
		krus1();
	}else{
		memset(a,0x3f,sizeof a);
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			a[u][v]=a[v][u]=w;
		}
		for(int i=1;i<=k;i++){
			cin>>c;
			for(int j=1;j<=n;j++){
				cin>>t[j];
			}
			for(int j=1;j<=n;j++){
				if(t[j]==0){
					for(int l=1;l<=n;l++){
						a[j][l]=a[l][j]=min(a[j][l],t[l]);
					}
				}
			}
		}
		krus2();
	}
	return 0;
}/*
1~4+A性质可以搞最小生成树 
6 11 1
1 2 4
2 3 6
3 4 5
2 5 8
2 6 5
3 6 7
1 3 7
4 6 6
5 6 4
3 5 9
1 4 6
0 0 3 6 7 8 0 
*/
