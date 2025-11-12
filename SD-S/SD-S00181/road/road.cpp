#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,cnt;
struct node{
	int u,v,w;
}a[1000006],b[100005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int c[20],vis[20],xiang[20][10005],p[20005],bian[10005];
int f(int x){
	if(p[x]==x) return x;
	return p[x]=f(p[x]);
}
void solve(int zong){
	for(int i=1;i<=n+1;i++) p[i]=i,bian[i]=ans+1;
	int zh1=1,zh2=1,anss=0;
	for(int i=1;i<=k;i++)
		if(vis[i]==1)
			for(int j=1;j<=n;j++) bian[j]=min(bian[j],xiang[i][j]);
	for(int i=1;i<=n;i++) b[i].u=n+1,b[i].v=i,b[i].w=bian[i];		
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		while(f(a[zh1].u)==f(a[zh1].v)&&zh1!=m+1) ++zh1;
		while(f(b[zh2].u)==f(b[zh2].v)&&zh2!=n+1) ++zh2;
		if(zh1==m+1&&zh2==n+1) break;
		if(zh1!=m+1&&zh2!=n+1){
			anss+=min(a[zh1].w,b[zh2].w);
			if(a[zh1].w<=b[zh2].w) p[f(a[zh1].u)]=f(a[zh1].v);
			else p[f(b[zh2].u)]=f(b[zh2].v);
		}
		else if(zh1!=m+1){
			anss+=a[zh1].w;
			p[f(a[zh1].u)]=f(a[zh1].v);
		}
		else{
			anss+=b[zh2].w;
			p[f(b[zh2].u)]=f(b[zh2].v);
		}
	}
	ans=min(ans,anss+zong);
	return;
}
void dfs(int xian,int zong){
	if(xian==k+1){
		solve(zong);
		return;
	}
	dfs(xian+1,zong);
	vis[xian]=1;
	dfs(xian+1,zong+c[xian]);
	vis[xian]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+1;i++) p[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>xiang[i][j];
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fu=f(a[i].u),fv=f(a[i].v);
		if(fu==fv) continue;
		ans+=a[i].w;
		b[++cnt]=a[i];
		p[fv]=fu;
		if(cnt==n-1) break;
	}
	for(int i=1;i<n;i++) a[i]=b[i];
	m=n-1;
	dfs(1,0);
	cout<<ans;
	return 0;
}
