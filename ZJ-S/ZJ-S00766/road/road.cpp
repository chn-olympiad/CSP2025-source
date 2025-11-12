#include <bits/stdc++.h>
using namespace std;
#define inf LONG_LONG_MAX
long long i,j,n,m,x,y,z,k,mi,c[10010],w[20][10010],f[10010];
vector<pair<long long,long long> >e[10010];
struct node{
	long long edge,x,y;
	bool operator > (node a) const{
		return edge>a.edge;
	}
};
priority_queue<node,vector<node>,greater<node> >pq;
long long prim(){
	long long fa,i,j,ans=0;
	for(i=1;i<=n;i++) f[i]=0;
	f[1]=1;fa=1;
	for(i=1;i<n;i++){
		for(j=0;j<e[fa].size();j++)
			pq.push((node){e[fa][j].first,fa,e[fa][j].second});
		while(f[pq.top().y]==1) pq.pop();
		f[pq.top().y]=1;fa=pq.top().y;
		ans+=pq.top().edge;
	}
	return ans;
}
void dfs(long long t,long long s){
	long long i,j,ans;
	if(t==k+1){
		ans=prim()+s;
		mi=min(mi,ans);
		return ;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j) e[i].push_back(make_pair(w[t][i]+w[t][j],j));
	dfs(t+1,s+c[t]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n-1;j++)
			e[i].pop_back();
	dfs(t+1,s);	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;mi=inf;
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		e[x].push_back(make_pair(z,y));
		e[y].push_back(make_pair(z,x));
	}
	if(k==0){
		cout<<prim();
		return 0;
	}
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++)
			cin>>w[i][j];
	}
	dfs(1,0);
	cout<<mi;
	return 0;
}
