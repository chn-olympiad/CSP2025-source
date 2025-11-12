#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+7;
long long a[N],b[15][N],c[15],n,m,k;
long long vis[N],dis[N],sum=0,z=0,mx=1e17+7;
struct node{
  long long to,val;
};
vector<node> G[N];
queue<long long >q;
void dfs(long long r){
  long long t,op,i;
  if(z==n){
  	if(mx>sum) mx=sum;
  	return;
  }
  
  for(i=0;i<G[r].size();i++){
  	t=G[r][i].to;
  	op=G[r][i].val;
  	if(vis[t]) continue;
  	if(sum+op>=mx) continue;
	vis[t]=1;
  	sum+=op;
  	if(t<=n) z++;
  	dfs(t);
  	vis[t]=0;
  	sum-=op;
  	if(t<=n) z--;
  }
}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  long long i,j,u,v,w,r,t,op;
  cin>>n>>m>>k;
  for(i=1;i<=m;i++){
  	cin>>u>>v>>w;
  	G[u].push_back({v,w});
  	G[v].push_back({u,w});
  }
  for(i=1;i<=k;i++){
  	cin>>c[i];
  	for(j=1;j<=n;j++){
  	  cin>>b[i][j];	
  	  G[n+i].push_back({j,b[i][j]});
  	  G[j].push_back({n+i,b[i][j]});
	}
  }
  z=1;
  vis[1]=1;
  dfs(1);
  /*q.push(1);
  while(!q.empty()){
  	r=q.front();
  	q.pop();
  	if(z==n){
  	  if(mx>sum) mx=sum;
  	  vis[r]=0;
  	  sum-=op;
  	  if(r<=n) z--;
  	  continue;
    }
	vis[r]=0;
  	sum-=op;
  	if(r<=n) z--;
  	for(i=0;i<G[r].size();i++){
  	  t=G[r][i].to;
  	  op=G[r][i].val;
  	  if(vis[t]) continue;
  	  if(sum+op>=mx) continue;
      vis[t]=1;
      sum+=op;
  	  if(t<=n) z++;
  	  q.push(t);
    }
  }*/
  cout<<mx;
  return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
89 856 565 654 546
*/
