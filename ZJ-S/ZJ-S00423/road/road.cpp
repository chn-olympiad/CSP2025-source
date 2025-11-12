#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e6+5;
int n,m,k;
int fa[N];
int a[15][N];
struct node{
	int u,v,w;
}e[N];
int getf(int x){
	//cout<<x<<" "<<fa[x]<<"\n";
	return (x==fa[x]?x:fa[x]=getf(fa[x]));
}
int kruskal(){
	int ans=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int fu=getf(e[i].u),fv=getf(e[i].v);
		//cout<<e[i].u<<" "<<e[i].v<<"\n";
		if(fu!=fv){
			fa[fv]=fu;
			ans+=e[i].w;
		}
	}
	return ans;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<kruskal();
	return 0;
}
//AFOed,I even can't solve T1