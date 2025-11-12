#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
struct node{
	int u,v,w;
}edge[N];
int fa[N],c[20],a[20][N],srt[N][20];
bool vis[20],b[20][N];
int n,m,cnt,k,x,y,z;
ll ans;
priority_queue<pair<int,pair<int,int> > >q;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void gether(int x,int y){
	x=find(x);
	fa[find(y)]=x;
}
void dfs(int x,ll sum){
	if(x>cnt){
		ans=min(ans,sum);
		return ;
	}
	if(srt[x][0])
		for(int i=1;i<=srt[x][0];i++){
			if(vis[srt[x][i]]){
				int l=edge[x].u,r=edge[x].v;
				int t1=b[srt[x][i]][l],t2=b[srt[x][i]][r];
				b[srt[x][i]][l]=b[srt[x][i]][r]=1;
				dfs(x+1,sum+a[srt[x][i]][x]*(1^b[srt[x][i]][l])+a[srt[x][i]][r]*(1^b[srt[x][i]][r]));
				b[srt[x][i]][l]=t1;b[srt[x][i]][r]=t1;
			}
			else {
				int l=edge[x].u,r=edge[x].v;
				vis[srt[x][i]]=1;
				b[srt[x][i]][l]=b[srt[x][i]][r]=1;
				dfs(x+1,sum+c[srt[x][i]]+a[srt[x][i]][x]*(1^b[srt[x][i]][l])+a[srt[x][i]][r]*(1^b[srt[x][i]][r]));
				b[srt[x][i]][l]=b[srt[x][i]][r]=0;
				vis[srt[x][i]]=0;
			}
		}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		q.push({-z,{x,y}});
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	} 
	for(int i=1;i<=n;i++) fa[i]=i;
	while(cnt<n-1){
		x=q.top().second.first;
		y=q.top().second.second;
		z=-q.top().first;q.pop();
		if(find(x)!=find(y)){
			ans+=z;cnt++;edge[cnt]={x,y,z};
			gether(x,y);
			for(int i=1;i<=k;i++)
				if(a[i][x]+a[i][y]<=z)
					srt[cnt][++srt[cnt][0]]=i;
		} 
	}
	//dfs(0,0);
	cout<<ans;
	return 0;
}
