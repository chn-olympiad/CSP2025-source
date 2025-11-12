#include <bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long n,m,k;
long long u[N],v[N],w[N];
long long fa[N];
long long cnt=0;
long long find(long long x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
bool vis[N];
long long c[N];
struct node{
	long long u,v,w,flag;
}q[N];
long long res=1e18;
void check(){
	//for(int i=1;i<=k;i++) cout<<vis[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	long long ans=0;
	long long tt=0;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			ans+=c[i];
			tt+=1;
		}
	}
	long long t=0;
	long long x,y;
	for(int i=1;i<=cnt;i++){
		int u=q[i].u,v=q[i].v,w=q[i].w;
		
		if(q[i].flag==0 && !vis[u%n]){
			//i=i+n+1;
			continue;
		}
		x=find(u),y=find(v);
		if(x==y){
			continue;
		}
		else{
			//cout<<u<<" "<<v<<" "<<w<<endl;
			fa[x]=y;
			ans+=w;
			t++;
		}
		if(t==tt+n-1) break;
	}
	res=min(res,ans);
}
void dfs(int u){
	if(u>k) {
		check();
		return;
	}
	vis[u]=1;
	dfs(u+1);
	vis[u]=0;
	dfs(u+1);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&q[i].u,&q[i].v,&q[i].w);
		q[i].flag=1;
	}
	cnt=m;
	long long w;
	int fg=1;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0) fg=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&w);
			q[++cnt].flag=0;
			q[cnt].u=n+i;
			q[cnt].v=j;
			q[cnt].w=w;
		}
	}
	sort(q+1,q+cnt+1,cmp);
	if(fg==1){
		for(int i=1;i<=k;i++){
			vis[k]=1;
		}
		check();
		cout<<res;
	}
	else{
		dfs(1);
		cout<<res;
	}
	
	return 0;
}
