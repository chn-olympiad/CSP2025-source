#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10,M=1e4+10,Max=pow(2,31)-1;
struct node{
	int v,w;
};
long long ans;
int dist[M],csh[M];
bool st[M];
int tp[N];
vector<node>g[N];
int n,m,k;
void add(int u,int v,int w){
	g[u].push_back({v,w});
}
void dij(int start){
	dist[start]=0;
	priority_queue<PII,vector<PII>,greater<PII> >q;
	q.push({0,start});
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int num=t.second,d=t.first;
		if(st[num]) continue;
		st[num]=true;
		for(int i=0;i<g[num].size();i++){
			int v=g[num][i].v;
			int w=g[num][i].w;
			if(dist[v]>d+w){
				dist[v]=d+w;
				q.push({dist[v],v});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	for(int i=1;i<=k;i++){
		cin>>csh[i];//不算城市 
		int sum=0;
		for(int j=1;j<=n;j++){
			cin>>tp[i];
		}
		for(int i=1;i<n;i++){
			for(int j=1+i;j<=n;j++){
				add(i,j,tp[i]+tp[j]);//在实现性质A的情况下 
			}
		}
	} 
	
	for(int i=1;i<=n;i++) dist[i]=Max;
	dij(1);
	for(int i=1;i<=n;i++){
//		if(dist[i]>csh[i]) ans+=csh[i];
		 ans+=dist[i];
//cout<<dist[i]<<" ";
	}
	cout<<ans;
	return 0;
}