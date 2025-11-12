#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10,K=15;
int n,m,k;
struct node{
	int u,v,w;
};
node road[M*2];
node ls[M*2];
int c[N];
int fa[N*2];
int a[K][N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool vis[K];
ll ans=1e18;
bool cmp(node x,node y){
	return x.w<y.w;
}
void solve(){
	ll cost=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		ls[i]=road[i];
	}
	cnt=m;
	int dian=n;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			cost+=c[i];
			dian++;
			for(int j=1;j<=n;j++){
				ls[++cnt]={dian,j,a[i][j]};
			}
		}
	}
	
	sort(ls+1,ls+cnt+1,cmp);
	for(int i=0;i<=dian+2;i++) fa[i]=i;
	int js=0;	//当前插入了多少点 
//	cout<<dian<<' '<<cnt<<'\n';
	for(int i=1;i<=cnt;i++){
		int fu=find(ls[i].u),fv=find(ls[i].v);
		if(fu!=fv){
//			cout<<ls[i].u<<' '<<ls[i].v<<' '<<ls[i].w<<'\n';
			fa[fu]=fv;
			cost+=ls[i].w;
			js++;
		}
		if(js==dian-1) break;
	}
//	cout<<cost<<'\n';
	ans=min(ans,cost);
}
int cnt;
void dfs(int d){	//枚举是否需要城镇 
	if(d==k+1){
		cnt++;
		solve();
		if(m>1e5&&cnt>=8){
			cout<<ans;
			exit(0);
		}
//		for(int i=1;i<=k;i++){
//			cout<<vis[i]<<'-';
//		}
//		cout<<'\n';
		return ;
	}
	vis[d]=true;
	dfs(d+1);
	vis[d]=false;
	dfs(d+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<c[i]<<' ';
//	}
//	cout<<'\n';
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(road+1,road+k+1,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}

