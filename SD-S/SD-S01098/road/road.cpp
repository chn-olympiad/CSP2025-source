#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e4+15;
int n,m,k,u,v,w;
struct node{
	int to;
	int w;
};
vector<node>e[N];
int vill[15][N];
vector<int>lst;
struct edge{
	int u;
	int v;
	int w;
};
int c[N];
vector<edge>ed,e_s;
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[N];
inline int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]); 
}
int ans=1e18;
inline int kruskal(){
	sort(ed.begin(),ed.end(),cmp);
	for(int i=1;i<=n+k;i++)	fa[i]=i;
	int sum=0;
	for(int i=0;i<ed.size();i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		if(find(u)==find(v))	continue;
		fa[find(u)]=find(v);
		sum+=w;
	}
	return sum;
}
int tree;
void dfs(int x,int sum){
	if(x==k+1){
		ed=e_s;
		for(int i=0;i<lst.size();i++){
			for(int j=1;j<=n;j++){
				ed.push_back({n+lst[i],j,vill[lst[i]][j]});
			}
		}
		ans=min(ans,kruskal()+sum);
		return;
	}
	dfs(x+1,sum);
	lst.push_back(x);
	dfs(x+1,sum+c[x]);
	lst.pop_back();
}
void solve_force(){
	dfs(1,0);
	cout<<ans;
}
void solve_special(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(vill[i][j]==0){
				for(int to=1;to<=n;to++){
					e_s.push_back({j,to,vill[i][to]});
				}
				break;
			}
		}
	}
	ed=e_s;
	cout<<kruskal();
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	bool scl=true;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		e_s.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])	scl=false;
		for(int j=1;j<=n;j++)	cin>>vill[i][j];
	}
	ed=e_s;
	tree=kruskal();
	if(k<=5)	solve_force();
	else if(scl)	solve_special();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
