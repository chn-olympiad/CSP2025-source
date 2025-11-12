#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct edgee{
	int u,v,w;
	bool operator<(const edgee a)const{
		return a.w<w;
	}
};
priority_queue<edgee>q;
int fa[30005];
int findd(int u){
	if(u==fa[u])return u;
	return fa[u]=findd(fa[u]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,N;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		edgee e;
		scanf("%d%d%d",&e.u,&e.v,&e.w);
		q.push(e);
	}
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++){
			edgee e;
			scanf("%d",&e.w);
			e.u=j;
			e.v=i+n; 
			q.push(e);
		}
	}
	N=n+k;
	for(int i=1;i<=N;i++)fa[i]=i;
	int cnt=0;long long ans=0;
	while(cnt<N-1){
		int u=q.top().u,v=q.top().v,w=q.top().w;
		q.pop();
		if(findd(u)==findd(v))continue;
		ans+=w;
		fa[findd(u)]=findd(v);
		cnt++;
	}cout<<ans;
	return 0;
} 
