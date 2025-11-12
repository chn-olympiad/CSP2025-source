#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10015],a[15][10005];
long long ans;
struct Node{
	int u,v,w;
}s[1000005],t[1100005],z[1100005];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x])	return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1;i<=m;i++)	cin>>s[i].u>>s[i].v>>s[i].w;
	int p=0;
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(s[i].u)!=find(s[i].v)){
			ans+=s[i].w;
			t[++p]={s[i].u,s[i].v,s[i].w};
			z[p]=t[p];
			fa[find(s[i].u)]=find(s[i].v);
		}
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)	cin>>a[i][j];
	for(int o=1;o<(1<<k);o++){
		int cnt=p;
		for(int i=1;i<=p;i++)	t[i]=z[i];
		long long x=0;
		for(int i=1;i<=k;i++){
			if((o>>i-1)&1){
				x+=a[i][0];
				for(int j=1;j<=n;j++)	t[++cnt]={i+n,j,a[i][j]};
			}
		}
		for(int i=1;i<=n+k;i++)	fa[i]=i;
		sort(t+1,t+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
			if(find(t[i].u)!=find(t[i].v)){
				x+=t[i].w;
				fa[find(t[i].u)]=find(t[i].v);
			}
		ans=min(ans,x);
	}
	cout<<ans;
	return 0;
}
