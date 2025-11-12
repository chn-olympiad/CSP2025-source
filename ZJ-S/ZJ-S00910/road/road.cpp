#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
#define MAXN 20005
#define MAXK 15
int n,m,k,c[MAXK],a[MAXK][MAXN];
struct Edge{
	int u,v,w;
	bool operator <(Edge t)const{
		return w>t.w;
	}
};
priority_queue<Edge> q1;
bool b[MAXK];
long long ans;
int fa[MAXN];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void check(){
	long long sum=0;
	priority_queue<Edge> q=q1;
	For(i,1,n+k){
		fa[i]=i;
	}
	int cnt=0;
	For(i,1,k){
		if(b[i]){
			cnt++;
		}
	}
	For(i,1,k){
		if(b[i]){
			sum+=c[i];
			For(j,1,n){
				if(a[i][j]!=-1){
					q.push(Edge{n+i,j,a[i][j]});
				}
			}
		}
	}
	while(!q.empty()){
		Edge e=q.top();
		q.pop();
		if(find(e.u)==find(e.v)){
			if(cnt==1&&e.u>n){
				a[e.u-n][e.v]=-1;
			}
			continue;
		}
		fa[find(e.u)]=find(e.v);
		sum+=e.w;
	}
	ans=min(ans,sum);
}
void dfs(int x){
	if(x==k+1){
		check();
		return ;
	}
	if(c[x]==0){
		b[x]=1;
		dfs(x+1);
	}else{
		b[x]=0;
		dfs(x+1);
		b[x]=1;
		dfs(x+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	priority_queue<Edge> q;
	For(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		q.push(Edge{u,v,w});
	}
	For(i,1,n){
		fa[i]=i;
	}
	while(!q.empty()){
		Edge e=q.top();
		q.pop();
		if(find(e.u)==find(e.v)){
			continue;
		}
		fa[find(e.u)]=find(e.v);
		q1.push(e);
	}
	For(i,1,k){
		cin>>c[i];
		For(j,1,n){
			cin>>a[i][j];
		}
	}
	ans=1e18;
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
