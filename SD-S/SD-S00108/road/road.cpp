#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int v,w;
};
vector<edge>e[1000005];
int dis[10005];
int c[15],a[15][10005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void dijk(int x){
	for(int i=1;i<=n;i++)dis[i]=1000000000;
	dis[x]=0;
	q.push({dis[x],x});
	while(!q.empty()){
		pair<int,int>a=q.top();
		int num=a.second;
		q.pop();
		for(auto i:e[num]){
			if(dis[i.v]>dis[num]+i.w){
				dis[i.v]=dis[num]+i.w;
				q.push({dis[i.v],i.v});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u1,v1,w1;
		cin>>u1>>v1>>w1;
		e[u1].push_back({v1,w1});
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int p=1;p<=n;p++)
		{
			cin>>a[j][p];
		}
	}
	dijk(1);
	cout<<dis[n];
	return 0;
}
