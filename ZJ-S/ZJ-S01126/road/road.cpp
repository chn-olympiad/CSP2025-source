#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct nd{
	int u,v;
	ll w;
};
nd a[1110000];
nd e[1110000];
int k;
int fa[100010];
ll b[21][100010];
ll c[21];
int getfa(int x){
	return fa[x]==x ? x : fa[x]=getfa(fa[x]);
}
bool cmp(nd x,nd y){
	return x.w<y.w;
}
ll kruskal(int m,int n){
	ll ans=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int cn=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		ll w=e[i].w;
		u=getfa(u),v=getfa(v);
		if(u!=v){
			cn++;
			ans+=w;
			fa[u]=v;
		}
		if(cn==n-1) break;
	}
	return ans;
}
int m,n;
bool vis[21];
ll work(){
	ll cnt=0;
	int o=0,g=0;
	//cout<<"1----------------1"<<endl;
	for(int i=1;i<=k;i++){
		if(vis[i]==1){
			cnt+=c[i];
			g++;
			for(int j=1;j<=n;j++){
				o++;
				e[m+o]={j,n+g,b[i][j]};
				//cout<<a[m+o].w<<endl;
			}
		}
	}
	for(int i=1;i<=m;i++){
		e[i]={a[i].u,a[i].v,a[i].w};
	}
	ll pp=kruskal(m+o,n+g);
	//cout<<pp<<" "<<cnt<<endl;
	cnt+=pp;
	return cnt;
}
ll ans=0x3f3f3f3f3f3f3f3f;
void dfs(int l){
	if(l==k+1){
		ans=min(ans,work());
	}
	else{
		for(int i=0;i<=1;i++){
			vis[l]=i;
			dfs(l+1);
			vis[l]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		a[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
