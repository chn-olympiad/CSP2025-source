#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=15;
const int N=1e4+25;
const int NN=1e3+25;
ll c[M],ans=0;
int fa[N];
ll dis[NN][NN];
priority_queue<pair<ll,pair<int,int>>>vec;
int find(int k){
	if(fa[k]==k)return k;
	else {
		int f=find(fa[k]);
		fa[k]=f;
		return f;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(k==0){
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			ll u,v,w;
			scanf("%lld%lld%lld",&u,&v,&w);
			vec.push(make_pair(-w,make_pair(u,v)));
		}
		int cnt=0;
		while(!vec.empty()){
			auto tp=vec.top();
			vec.pop();
			ll w=tp.first;
			int u=tp.second.first;
			int v=tp.second.second;
			if(find(u)==find(v))continue;
			else fa[u]=find(v);
			cnt++;
			if(cnt>=n)break;
			ans+=w;
		}
		printf("%lld",-ans);
	}
	else{
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			ll u,v,w;
			scanf("%lld%lld%lld",&u,&v,&w);
			dis[u][v]=dis[v][u]=w;
		}
		for(int i=1;i<=k;i++){
			scanf("%lld",&c[i]);
			ll w;
			for(int j=1;j<=n;j++){
				scanf("%lld",&w);
				dis[n+i][j]=dis[j][n+i]=w;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ll w=1e18;
				for(int r=1;r<=k;r++){
					ll ds=dis[i][n+r]+dis[n+r][j];
					w=min(w,ds);
				}
				if(dis[i][j]!=0)w=min(dis[i][j],w);
				vec.push(make_pair(-w,make_pair(i,j)));
			}
		}
		int cnt=0;
		while(!vec.empty()){
			auto tp=vec.top();
			vec.pop();
			ll w=tp.first;
			int u=tp.second.first;
			int v=tp.second.second;
			if(find(u)==find(v))continue;
			else fa[u]=find(v);
			cnt++;
			if(cnt>=n)break;
			ans+=w;
		}
		printf("%lld",-ans);
	}
	return 0;
}