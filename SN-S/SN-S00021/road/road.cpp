#include<bits/stdc++.h>
using namespace std;
int fa[10010],w[12][10010];
int n,m,k;
long long minn=998244353;
struct edge{
	int u,v;
	long long w;
	friend bool operator<(edge aa,edge bb){
		return aa.w>bb.w;
	}
};
struct node{
	int u,v;
	long long w;
}e[1000010];
priority_queue<edge> q;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
long long prim(){
	for(int i=1;i<=(n+k);i++){
		fa[i]=i;
	}
	for(int j=1;j<=m;j++){
		q.push({e[j].u,e[j].v,e[j].w});
	}
	long long ans=0;
	while(!q.empty()){
		int u,v;
		long long w;
		u=q.top().u;v=q.top().v;w=q.top().w;
		q.pop();
		if(find(fa[u])==find(fa[v])) continue;
		fa[find(u)]=find(fa[v]);
		ans+=w;
	}
	return ans;
}
long long min1(long long a,long long b){
	return a<=b?a:b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(k==0){
		cout<<prim()<<endl;
		return 0; 
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>w[i][j];
		}
	}
	for(int i=0;i<=(1<<k)-1;i++){
		long long ans1=0;
		int y=i;
		int cnt=0;
		for(int j=1;j<=k;j++){
			if(y&1){
				++cnt;
				ans1+=w[j][0];
				for(int z=1;z<=n;z++){
					q.push({n+cnt,z,w[j][z]});
				}
			}
			y>>=1;
		}
		minn=min1(minn,prim()+ans1);
	}
	cout<<minn<<endl;
	return 0;
}
