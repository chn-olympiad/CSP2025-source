#include<bits/stdc++.h>
using namespace std;
int n, m, k, fa[2010], c[110], len;long long ans=LONG_LONG_MAX/8;
bool vis[1010];
struct node{
	int u, v, w, fl;
}a[4000010];
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}
bool cmp(node &x, node &y){
	return x.w<y.w;
}
long long f(int cnt){
	long long sum=0;
	int le=0;
	for(int i=1;i<=len;i++){
		if(!vis[a[i].fl]||get(a[i].u)==get(a[i].v))continue;
		int x=get(a[i].u), y=get(a[i].v);
		fa[x]=y;sum+=a[i].w;le++;
		if(le==n+cnt-1)return sum;
	}
	return sum;
}
void dfs(int pos, long long sum, int cnt){
	if(pos>k){
		ans=min(ans,f(cnt)+sum);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		return;
	}
	vis[pos]=1;
	dfs(pos+1,sum+c[pos],cnt+1);
	vis[pos]=0;
	dfs(pos+1,sum,cnt);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	vis[0]=1;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	len=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			int v;
			scanf("%d",&v);
			a[++len]={i+n,j,v,i};
		}
	}
	sort(a+1,a+1+len,cmp);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}