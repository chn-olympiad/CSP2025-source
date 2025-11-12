#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int city,w;
};
vector <road> e[10110];
vector <int> e2[10110];
int vis[10110];
int village[50];
int rd[1000010][4];
int ans=2e9;
void bfs(){
	queue <int> q;
	q.push(1);
	vis[1]=1;
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int it=0;it<(int)e2[x].size();it++){
			if (vis[e2[x][it]]==0){
				q.push(e2[x][it]);
				vis[e2[x][it]]=1;
			}
		}
	}
}
void check(int pos,int cnt,int cost){
	if (pos>m){
		memset(vis,0,sizeof(vis));
		bfs();
		for (int i=1;i<=n;i++)
			if (vis[i]==0) return;
		ans=min(cost,ans);
		return;
	}
	e2[rd[pos][1]].push_back(rd[pos][2]);
	check(pos+1,cnt+1,cost+rd[pos][3]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		rd[i][1]=u;
		rd[i][2]=v;
		rd[i][3]=w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for (int i=1;i<=k;i++){
		int c;
		cin>>c;
		village[i]=c;
		for (int j=1;j<=n;j++){
			int w;
			cin>>w;
			e[n+i].push_back({j,w});
		}
	}
	check(1,0,0);
//	int l=1,r=m+1,ans=m;
//	while (l<r){
//		int mid=(l+r)/2;
//		if (check(1,0,0,mid)){
//			r=mid;
//			ans=mid;
//		}else{
//			l=mid+1;
//		}
//	}
	bfs();
	cout<<ans;
	return 0;
}
