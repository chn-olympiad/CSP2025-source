#include<bits/stdc++.h>
using namespace std;


long long n,m,k;
bool vis[10010];
long long ci[10010];

struct nod{
	long long to,q;
	friend bool operator <(nod a,nod b){
		return a.q>b.q;
	}
};
vector<nod> rod[10010];
priority_queue<nod> edg;
long long dis[10010][13];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=n;i++){
		long long u,v,w;
		ci[i]=INT_MAX;
		scanf("%lld%lld%lld",&u,&v,&w);
		rod[u].push_back({v,w});
		rod[v].push_back({u,w});
	}
	for(long long i=1;i<=k;i++){
		long long c;
		scanf("%lld",&c);
		for(long long j=1;j<=n;j++){
			long long qwe;
			scanf("%lld",&qwe);
			ci[i]=min(ci[i],qwe);
		}
	}
	
	long long ar=1,dis=0;
	vis[1]=1;
	for(nod nxt:rod[1]){
		edg.push(nxt);
	}
	while(!edg.empty()&&ar<n){
		nod nw=edg.top();
		edg.pop();
		if(vis[nw.to]==1)continue;
		vis[nw.to]=1;
		dis+=nw.q;
		for(nod nxt:rod[nw.to]){
			if(vis[nxt.to]!=1)edg.push(nxt);
		}
	}
	printf("%lld",dis);
	return 0;
}
/*
muqian16pts
teshuxingzhiA 
youyu c=0 代价相等
ci[i]keyifugaichengzuixiaode


*/