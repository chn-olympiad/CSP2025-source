#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10;
struct node{
	int u,v,w;
}edge[N];
int c[N],a[11][N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[N];
int find(int a){
	if(fa[a]==a)return a;
	return fa[a]=find(fa[a]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k!=0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(edge+1,edge+m+1,cmp);
	int ans=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1)break;
		int gx=find(edge[i].u),gy=find(edge[i].v);
		if(gx==gy)continue;
		fa[gx]=gy;
		ans+=edge[i].w;
		cnt++;
	}
	cout<<ans;
	return 0;
}
