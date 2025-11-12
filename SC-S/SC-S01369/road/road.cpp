#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+1e4+5,K=15;
int n,m,k,cnt,ans,c[K],fa[N];
bool vis[K],use[N+K];
struct edge{
	int u,v,w;
	bool operator<(const edge x)const{
		return w>x.w;
	}
}e[M];
priority_queue<edge>q;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(!k){
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=1;i<=m;i++)
			cin>>e[i].u>>e[i].v>>e[i].w;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu!=fv){
				fa[fv]=fu;
				cnt++;
				ans+=e[i].w;
				if(cnt==n-1)
					break;
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			q.push({u,v,w});
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				int w;
				cin>>w;
				q.push({n+i,j,c[i]+w}),m++;
			}
		}
		for(int i=1;i<=m;i++){
			if(!q.empty()&&q.top().u>n&&vis[q.top().u-n]){
				edge u=q.top();
				q.pop();
				q.push({u.u,u.v,u.w-c[u.u-n]});
			}
			edge u=q.top();
			q.pop();
			if((u.u>n&&!use[u.v])||(!use[u.u]||!use[u.v])){
				if(u.u>n)
					vis[u.u-n]=1;
				ans+=u.w;
				cnt+=(u.u<=n&&!use[u.u])+(!use[u.v]);
				use[u.u]=use[u.v]=1;
				if(cnt>=n)
					break;
			}
		}
		cout<<ans;
	} 
	return 0;
}