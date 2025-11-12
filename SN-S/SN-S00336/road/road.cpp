//SN-S00336 李宸昊 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define inf 0x3f3f3f3f
#define ll long long
const int maxn=1e6+5;
int n,m,k,c[15][maxn];
//vector<pair<int,int> > e[maxn];
//struct node{
//	int u,num,r;
//};
//priority_queue<node,vector<node>,greater<node> > pq;
signed main(){
	freopen("road3.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	rep(i,1,m){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({v,w});
	}
	rep(i,1,k) rep(j,1,n) cin>>c[i][j];
	pq.push({1,0,0});
	while(!pq.empty()){
		node nd=pq.top();
		pq.pop();
		int u=nd.u,num=nd.num,r=nd.r,cst=inf,np;
		for(auto [v,w]:e[u]) if(w<cst) np=v,cst=w;
		rep(i,1,k) if(c[i][j]<cst) if(r&(1<<i))
	}
	return 0;
}

