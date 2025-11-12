#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
struct note{
	int x,y,w;
}e[1000010];
vector<int> edge[N];
int cnt,f[N],i,x,y,ans,z,n,m,k,j,c[20],a[20][N];
void add(int x,int y,int z){
	cnt++;
	e[cnt]={x,y,z};
}
bool cmp(note a,note b){return a.w<b.w;}
void dfs(int u,int fa){
	int i,v;
	for(i=0;i<edge[u].size();i++){
		v=edge[u][i];
		if(v==fa)continue;
		if(f[v]==1)continue;
		f[v]=1;
		dfs(v,u);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(e+1,e+1+cnt,cmp);
	for(i=1;i<=cnt;i++)
		if(f[e[i].y]==0||f[e[i].x]==0){
			edge[e[i].x].push_back(e[i].y);
			edge[e[i].y].push_back(e[i].x);
			f[e[i].x]=1;
			dfs(e[i].x,0);
//			cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].w<<"\n";
			ans+=e[i].w;
		}
	cout<<ans;
	return 0;
}
/*
5 6 0
1 5 4
1 3 6
5 3 2
5 4 2
4 3 3
2 3 1
*/
