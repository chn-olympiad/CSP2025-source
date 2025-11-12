#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
int b[15],tot;
bool vis[N+15];
long long c[15],a[15][N],ans;
vector<pair<int,long long> >g[N];
vector<int>p;
long long min_tree(){
	long long res=0;
	priority_queue<pair<long long,int> >q;
	for(int i=0;i<p.size();i++){
		res+=c[p[i]];
		q.push(make_pair(-a[p[i]][1],p[i]+n));//n+1~n+k
	}
	for(int i=0;i<g[1].size();i++)
		q.push(make_pair(-g[1][i].second,g[1][i].first));
	memset(vis,false,sizeof(vis));
	vis[1]=true;
	int cnt=n-1;
	while(!q.empty()){
		int u=q.top().second;long long t=q.top().first;q.pop();
		if(vis[u]) continue;
		res+=-t,vis[u]=true;
		if(res>=ans) return ans;
		if(u>n){
			u-=n;
			for(int i=2;i<=n;i++)
				if(!vis[i])
					q.push(make_pair(-a[u][i],i));
		}
		else{
			cnt--;
			if(cnt==0) break;
			for(int i=0;i<g[u].size();i++){
				int v=g[u][i].first;long long w=g[u][i].second;
				if(vis[v]) continue;
				q.push(make_pair(-w,v));
			}
			for(int i=0;i<p.size();i++)
				if(!vis[p[i]+n])
					q.push(make_pair(-a[p[i]][u],p[i]+n));
					
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y;long long z;
		scanf("%d%d%lld",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	for(int i=1;i<=k;i++)
		if(c[i]) b[++tot]=i;
	if(tot<=5){
		ans=1e18;
		for(int x=0;x<(1<<tot);x++){
			for(int i=1;i<=k;i++)
				if(!c[i]) p.push_back(i);
			for(int i=1;i<=tot;i++){
				int t=(x>>(i-1))&1;
				if((x>>(i-1))&1) p.push_back(b[i]);
			}
			ans=min(ans,min_tree());
			p.clear();
		}
	}
	printf("%lld",ans);
	return 0;
}
