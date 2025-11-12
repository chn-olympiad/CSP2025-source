#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,fl=0,fa[10105],vis[15],b[15],c[11][10005];
ll ans=0;
struct node{
	int u,v,w;
}a[1100005];
bool cmp(node x,node y){
	return x.w<y.w;
}
void init(int x){
	for(int i=1;i<=x;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void check(ll summ,int y){
	int cnt=m+k*n;
	ll sum=summ;
	int tot=n+y,res=0;
	init(n+k);
	for(int i=1;i<=cnt;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(u>n&&vis[u-n]==0) continue;
		int uu=find(u),vv=find(v);
		if(uu==vv) continue;
		res++,sum+=w;
		if(sum>=ans) return;
		fa[uu]=vv;
		if(res==tot-1) break;
	}
	ans=min(ans,sum);
}
void dfs(int x,ll sum,int y){
	if(x>k){
		check(sum,y);
		return;
	}
	vis[x]=1;
	dfs(x+1,sum+b[x],y+1);
	vis[x]=0;
	dfs(x+1,sum,y);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	if(k==0){
		int cnt=m,tot=n,res=0;
		init(tot);
		sort(a+1,a+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int uu=find(u),vv=find(v);
			if(uu==vv) continue;
			res++,ans+=w;
			fa[uu]=vv;
			if(res==tot-1) break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++) cin>>c[i][j];
		if(b[i]!=0) fl=1;
	}
	if(!fl){
		int cnt=m+k*n,tot=k+n,res=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				int pos=m+(i-1)*n+j;
				a[pos].u=i+n,a[pos].v=j,a[pos].w=c[i][j];
			}
		}
		sort(a+1,a+cnt+1,cmp);
		init(tot);
		for(int i=1;i<=cnt;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int uu=find(u),vv=find(v);
			if(uu==vv) continue;
			res++,ans+=w;
			fa[uu]=vv;
			if(res==tot-1) break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int pos=m+(i-1)*n+j;
			a[pos].u=i+n,a[pos].v=j,a[pos].w=c[i][j];
		}
	}
	sort(a+1,a+(m+n*k)+1,cmp);
	ans=0x3f3f3f3f3f3f3f3f;
	dfs(1,0ll,0);
	cout<<ans;
	return 0;
}