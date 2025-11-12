#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath> 
#include<queue>
#include<algorithm>
#include<bitset>
#include<vector>
#define int long long
using namespace std;
const int N=1e6+111;
int he[N],ne[2*N],to[2*N],cnt,w[2*N];
int c[11],a[11][N],n,m,k,vis[N],vis11[11],tot;
void add(int u,int v,int we){
	to[++cnt]=v;
	ne[cnt]=he[u];
	he[u]=cnt;
	w[cnt]=we;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//freopen("road3.in","r",stdin);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,we;
		scanf("%lld%lld%lld",&u,&v,&we);
		add(u,v,we);add(v,u,we);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			int wa;
			scanf("%lld",&wa);
			a[i][j]=wa;
			add(i+n,j,wa+c[i]);add(j,i+n,wa+c[i]);
		} 
	}
	int s=1,ans=0;
	q.push({0,s});
	while(!q.empty()){
		s=q.top().second;
		int val=q.top().first;
		q.pop();
		if(vis[s]) continue;
		ans+=val;vis[s]=1;
		if(s<=n) tot++;
		if(tot==n) break;
		for(int i=he[s];i;i=ne[i]){
			int v=to[i];
			if(!vis[v]){
			    if(s>n){
			    	q.push({a[s-n][v],v});
		        }
				else q.push({w[i],v});
			}
		}
	}
	cout<<ans;
	return 0;
}