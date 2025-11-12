#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
}e[2000010],e1[6000010];
bool cmp(node aa,node bb){
	return aa.w<bb.w;
}
int n,m,k,a[15][10010],b[15],c[15],v[15],p,ans,t,fa[10010],minn;
int find(int x){
	if (fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int kr(){
	int ans1=0,m1=m,tt=0;
	
	for (int i=1;i<=m;i++) e1[i]=e[i];
	for (int i=1;i<=k;i++){
		if (v[i]) ans1+=c[i];else continue;
		for (int j=1;j<=n;j++)
			for (int j2=j+1;j2<=n;j2++){
				e1[++m1].u=j2;
				e1[m1].v=j;
				e1[m1].w=a[i][j]+a[i][j2];
			}
	}
	if (ans1>=minn) return minn;
	for (int i=1;i<=n;i++) fa[i]=i;
	sort(e1+1,e1+1+m1,cmp);
	for (int i=1;i<=m1;i++){
		int xx=e1[i].u,yy=e1[i].v;
		if (find(xx)==find(yy)) continue;
		fa[fa[xx]]=fa[yy];
		ans1+=e1[i].w;tt++;
		if (ans1>=minn) return minn;
		if (tt==n-1) return ans1;
	}
}
void dfs(int x){
	if (x>k){
		int r=kr();
		if (r<minn) minn=r;
		return;
	}
	v[x]=1;
	dfs(x+1);
	v[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		if (c[i]) p=1;
		int pp=0;
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
			if (a[i][j]==0) pp=1,b[i]=j;
		}
		if (!pp) p=1;
	}
	if (!p){
		for (int i=1;i<=k;i++){
			for (int j=1;j<=n;j++)
				if (b[i]!=j){
					e[++m].u=b[i];
					e[m].v=j;
					e[m].w=a[i][j];
				}
		}
		for (int i=1;i<=n;i++) fa[i]=i;
		sort(e+1,e+1+m,cmp);
		for (int i=1;i<=m;i++){
			int xx=e[i].u,yy=e[i].v;
			if (find(xx)==find(yy)) continue;
			fa[fa[xx]]=fa[yy];
			ans+=e[i].w;t++;
			if (t==n-1){
				cout<<ans;return 0;
			}
		}
	}
	minn=100000000000000000;
	dfs(1);
	cout<<minn;
	return 0;	
}