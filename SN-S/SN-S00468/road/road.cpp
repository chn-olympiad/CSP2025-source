#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,d;
}e[1000005];
int c[12],f[12][10005];
bool cmp(node x,node y){
	return x.d<y.d;
}
int fa[10005];
int find(int x){
	while(fa[x]!=x)x=fa[x]=fa[fa[x]];
	return x;
}
void merge(int x,int y){
	if(find(x)!=find(y)){
		fa[find(x)]=fa[find(y)];
	}
}
signed main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].d;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>f[i][j];
	}
	sort(e+1,e+m+1,cmp);
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].v)!=find(e[i].u)){
			merge(e[i].v,e[i].u);
			ans+=e[i].d;	
		}
	}
	cout<<ans;
   return 0;
}

