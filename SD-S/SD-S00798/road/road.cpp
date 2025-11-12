#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,m,k;
struct zuoti{
	int u;
	int v;
	int info;
};
bool operator < (zuoti a,zuoti b){
	return a.info>b.info;
}
priority_queue<zuoti>pq;
int fa[10005];
int find(int x){
	if(fa[x]==0)return x;
	else {
		return fa[x]=find(fa[x]);
	}
}
int merge(int a,int b){
	fa[find(a)]=b;
}
//vector<pair<int,int> >e[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,info;
		cin >> u >> v >> info;
//		e[u].push_back({v,info});
//		e[v].push_back({u,info});
		pq.push({u,v,info});
	}
	for(int i=1;i<=k;i++){
		int cj;
		cin >> cj;
		for(int j=1;j<=n;j++){
			int info;
			cin >> info;
//			e[j].push_back({n+i,info});
//			e[n+i].push_back({j,info});
			pq.push({j,n+i,info});
		}
	}
	int ans=0;
	while(!pq.empty()){
		zuoti tmp=pq.top();
		pq.pop();
		int t1=tmp.u,t2=tmp.v;
		if(find(t1)!=find(t2)){
			merge(t1,t2);
			ans+=tmp.info;
		}
	}
	cout << ans;
	return 0;
}
