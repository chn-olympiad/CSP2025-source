#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,k,ans=0;
int c[N],a[N];
bool vis[N];
vector<pair<int,int> >z[N];
priority_queue<pair<int,int> >q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		z[u].push_back({-w,v});
		z[v].push_back({-w,u});
	}
	vis[1]=1;
	for(auto i:z[1]) q.push(i);
	while(!q.empty()){
		int v=q.top().second,w=-q.top().first;
		q.pop();
		if(!vis[v]){
			vis[v]=1;
			ans+=w;
			for(auto i:z[v]) q.push(i);
		}
	}
	printf("%d",ans);
	return 0;
}
/*
5 7 0
1 2 1
1 3 4
1 4 2
1 5 3
2 4 3
4 5 2
3 5 1
*/
