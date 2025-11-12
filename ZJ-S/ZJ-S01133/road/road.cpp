#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
typedef pair<int,int> pr;
long long ans;
set<int> st;
int cnt=1;
int n,m,k;
vector<pr> edge[N];
int road[15][N];
void dij(int p){
	st.insert(p);
	priority_queue<pr,vector<pr> ,greater<pr> > q;
	for(int i = 0;i < edge[p].size();i++){
		q.push(edge[p][i]);
	}
	while(!q.empty() || cnt < n){
		pr nw = q.top();
		int x = nw.second;
		q.pop();
		if(st.count(x)) continue;
		ans += nw.first;
		st.insert(x);
		cnt++;
		for(int i = 0;i < edge[x].size();i++){
			if(!st.count(edge[x][i].second)){
				q.push(edge[x][i]);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[u].push_back(pr(w,v));
		edge[v].push_back(pr(w,u));
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d",&road[i][j]);
		}
	}
	dij(1);
	printf("%lld",ans);
	return 0;
}
