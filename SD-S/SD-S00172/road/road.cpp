#include<bits/stdc++.h>
#define int long long
#define pb push_back
const int N=1e4+100;
const int M=1e6;
using namespace std; 
struct node{
	int to,w;
};
struct nodee{
	int u,v,w;
}sg[M];
bool cmp(nodee a,nodee b){
	return a.w<b.w;
}
int c[N],a[N][N],fa[N],tt=0;
vector<node> e[N];
int n,m,k,ans=0; 
int getfa(int x){
	return (fa[x]==x?x:fa[x]=getfa(fa[x]));
}
bool flag
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb({v,w});
		e[v].pb({u,w});
		sg[++tt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(sg+1,sg+tt+1,cmp);
		for(int i=1;i<=tt;i++){
			if(getfa(sg[i].u)!=getfa(sg[i].v)){
				ans+=sg[i].w;
				fa[getfa(sg[i].u)]=getfa(sg[i].v);
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}
