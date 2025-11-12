#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int u[1000005],v[1000005],w[1000005];
bool vis[1000005];
vector <int> a[1000005][2];
int n,m,k;
queue <int> q,qw;
void bfs(){
	while(q.empty()){
		int t=q.front(),wt=qw.front();
		q.pop();
		qw.pop();
		for(int i=0;i<a[t][1].size();i++){
			q.push(a[t][1][i]);
			qw.push(a[t][0][i]+wt);
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		a[u[i]][1].push_back(v[i]);
		a[u[i]][0].push_back(w[i]);
		a[v[i]][1].push_back(u[i]);
		a[v[i]][0].push_back(w[i]);
	}
	if(k==0){
		q.push(1);
		qw.push(0);
		vis[1]=true;
		bfs();
	}else{
		cout<<0;
	}
	return 0;
}
