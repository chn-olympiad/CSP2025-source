#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+25,K=10+25;
struct node{
	int v,w;
};
vector<node> e[N];
int c[K],a[K][N],n,m,k,ans=1e16,zd[N];
bool yy[K],vis[N];
priority_queue<pair<int,int>> p;
void zdl(int x){
	int sum=0;
	while(!p.empty()){
		p.pop();
	}
	for(int i=1;i<=n+k;i++){
		vis[i]=0;
		zd[i]=1e16;
	}
	vis[1]=1;
	zd[1]=0;
	for(node i:e[1]){
		p.push({-i.w,i.v});
		zd[i.v]=i.w;
	}
	for(int i=1;i<=k;i++){
		if(yy[i]==0){
			continue;
		}
		if(a[i][1]<zd[n+i]){
			p.push({-a[i][1],n+i});
			zd[n+i]=a[i][1];
		}
	}
	while(!p.empty()){
		int ww=-p.top().first,vv=p.top().second;
		p.pop();
	//	cout<<vv<<" "<<ww<<"--\n";
		if(vis[vv]){
			continue;
		}
		vis[vv]=1;
		sum+=ww;
		if(vv<=n){
			for(node i:e[vv]){
				if(vis[i.v]){
					continue;
				}
				if(i.w<zd[i.v]){
					zd[i.v]=i.w;
					p.push({-i.w,i.v});
				}
			}
			for(int i=1;i<=k;i++){
				if(yy[i]==0){
					continue;
				}
				if(vis[i+n]){
					continue;
				}
				if(a[i][vv]<zd[n+i]){
					zd[n+i]=a[i][vv];
					p.push({-a[i][vv],n+i});
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(vis[i]){
					continue;
				}
				if(a[vv-n][i]<zd[i]){
					zd[i]=a[vv-n][i];
					p.push({-a[vv-n][i],i});
				}
			}
		}
	}
	ans=min(ans,sum+x);
//	cout<<sum+x<<" "<<x<<" "<<c[1]<<"^^\n";
	return;
}
void dfs(int x,int y){
	if(x==k+1){
		zdl(y);
		return;
	}
	if(c[x]==0){
		yy[x]=1;
		dfs(x+1,y);
	}
	else{
		dfs(x+1,y);
		yy[x]=1;
		dfs(x+1,y+c[x]);
		yy[x]=0;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		e[uu].push_back({vv,ww});
		e[vv].push_back({uu,ww});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dfs(1,0);
	cout<<ans;
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
