#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[10005][15],ans=1e18,a[15],dis[10015],vis2[15];
vector<pair<int,int> >edges[10005],g[10005];
bool vis[10015];
int read(){
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return f*sum;
}
int prim(int n){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dis[i]=1e18;
	}
	int ans=0,cnt=1;
	queue<int>q;
	q.push(1);
	vis[1]=1;
	while(cnt<n){
		int x=q.front(),minn=1e18,minx;
		q.pop();
		for(auto y:edges[x])dis[y.first]=min(dis[y.first],y.second);
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(dis[i]<minn){
				minn=dis[i];
				minx=i;
			}
		}
		ans+=minn;
		q.push(minx);
		vis[minx]=1;
		cnt++;
	}
	return ans;
}
void dfs(int x,int sum,int cnt){
	if(x==k+1){
		for(int i=1;i<=cnt;i++){
			g[i+n]=edges[i+n];
			for(int j=1;j<=n;j++){
				g[j]=edges[j];
				edges[j].push_back({i+n,c[j][vis2[i]]});
				edges[i+n].push_back({j,c[j][vis2[i]]});
			}
		}
		ans=min(ans,prim(n+cnt)+sum);
		for(int i=1;i<=n+cnt;i++)edges[i]=g[i];
		return;
	}
	vis2[++cnt]=x;
	dfs(x+1,sum+a[x],cnt);
	cnt--;
	dfs(x+1,sum,cnt);
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),w=read();
		edges[x].push_back({y,w});
		edges[y].push_back({x,w});
	}
	for(int i=1;i<=k;i++){
		a[i]=read();
		for(int j=1;j<=n;j++)c[j][i]=read();
	}
	dfs(1,0,0);
	cout<<ans;
}
