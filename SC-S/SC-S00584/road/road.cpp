#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
struct S{
	int u,v,w;
}a[100050];
struct Edge{
	long long v,w;
};
vector<Edge> e[100050];
long long vi[100050][50];
long long dis[100050];
queue<Edge> q;
void djstra(){
	bool visit[100050]={0};
	for(int i=1;i<=n;i++){
		dis[i]=INT_MAX/2;
	}
	dis[1]=0;
	q.push({1,0});
	while(!q.empty()){
		Edge u=q.front();
		q.pop();
		if(visit[u.v])continue;
		visit[u.v]=1;
		int len=e[u.v].size();
		for(int i=0;i<len;i++){
			int v=e[u.v][i].v;
			long long w=e[u.v][i].w;
			if(dis[v]<w+dis[u.v]){
				dis[v]=w+dis[u.v];
				q.push({v,u.v});
				
			}
		}
		
	}
	
}
bool cmpp(S a,S b){
	if(a.u!=b.u) return a.u<b.u;
    return a.w<b.w;
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		//int u ,v, w;
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&vi[i][j]);
		}
	}
	sort(a+1,a+1+m,cmpp);
    for(int i=1;i<=m;i++){
		e[a[i].u].push_back({a[i].v,a[i].w});
		e[a[i].v].push_back({a[i].u,a[i].w});
	}
	djstra();
	printf("%lld",dis[n]);
	return 0;
}