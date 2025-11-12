#include<bits/stdc++.h>
using namespace std;
int fa[10050],n;
struct node{
	int u,v,w;
};
bool cmp(node uu,node oo){
	return uu.w<oo.w;
}
node a[1000050];
node b[10050];
node p[110050];
int c[15],x[15][10050];
int f[15];
int tot=0;
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
long long ans=0;
int id[15],t;
void solve(){
	for(int i=1;i<=n+t;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n-1;i++){
		p[i]=b[i];
	}
	int len=n-1;
	long long sum=0;
	for(int i=1;i<=t;i++){
		sum+=c[id[i]];
		for(int j=1;j<=n;j++){
			++len;
			p[len].u=n+i;
			p[len].v=j;
			p[len].w=x[id[i]][j];
		}
	}
	sort(p+1,p+len+1,cmp);
	for(int i=1;i<=len;i++){
		int tx=find(p[i].u),ty=find(p[i].v);
		if(tx!=ty){
			fa[tx]=ty;
			sum+=p[i].w;
		}
	}
	ans=min(ans,sum);
	return;
}
void dfs(int l,int r){
	if(l==r+1){
		solve();
		return;
	}
	dfs(l+1,r);
	if(f[l]){
		id[++t]=l;
		dfs(l+1,r);
		--t;		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&x[i][j]);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int tx=find(a[i].u),ty=find(a[i].v);
		if(tx!=ty){
			fa[tx]=ty;
			ans+=a[i].w;
			b[++tot]=a[i];
		}
	}
	t=1;
	long long hhh=ans;
	for(int i=1;i<=k;i++){
		id[1]=i;
		solve();
		if(hhh>ans){
			f[i]=1;
		}
	}
	t=0;
	dfs(1,k);
	cout<<ans;
	return 0;
} 
