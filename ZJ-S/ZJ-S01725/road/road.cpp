#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,k,c[15],a[15][N],dis[N],tmp=0;
vector < pair<int,int> >  v[N];
bool vis[N],used[N];
long long ans=0; 
void spfa(int s){
	priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0,s));used[s]=1;
	while(!q.empty()){
		ans+=q.top().first;
        int u=q.top().second;q.pop();
		if(used[u]) continue;
		used[u]=1;
        for(int i=0;i<v[u].size();i++){
        	int t=v[u][i].first;
        	if(used[t]) continue;
			q.push(make_pair(v[u][i].second,t));
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(vis,0,sizeof(vis));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back(make_pair(y,z));
		v[y].push_back(make_pair(x,z));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	cout<<ans<<endl;
	return 0;
}
