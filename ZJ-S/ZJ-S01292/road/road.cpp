#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Road{
	int from,to,cost;
}ro[1000005],roo[2500000];
int cnt,cnt0;
struct City{
	int vis,type;
}ci[10100];
bool cmp(Road a,Road b){
	return a.cost<b.cost;
}
int n,m,k;
bool fix[15];
int co[15][10005],fi[15];
int AC=LLONG_MAX-INT_MAX,ans,sum;
int fa[10020];
inline void init(){
	for(int i=1;i<=n+20;i++) fa[i]=i;
	ans=sum=0;
	for(int i=1;i<=k;i++) if(fix[i]) sum++,ans+=fi[i];
	memset(roo,0,sizeof(roo));
	for(int i=1;i<=cnt0;i++) roo[i].from=ro[i].from,roo[i].to=ro[i].to,roo[i].cost=ro[i].cost;
	cnt=cnt0;
	for(int i=1;i<=k;i++){
		if(fix[i]){
			for(int j=1;j<=n;j++){
				roo[++cnt].to=j;
				roo[cnt].from=n+i;
				roo[cnt].cost=co[i][j];
			}
		}
	}
	sort(roo+1,roo+cnt+1,cmp);
	return;
}
inline find(int n1){
	if(fa[n1]==n1) return n1;
	return fa[n1]=find(fa[n1]);
}
inline void kruskal(){
	for(int i=1,cho=0;i<=cnt,cho<=n+sum-1;i++){
		if(i>cnt||cho>n+sum-1) break;
		int tot1=roo[i].from,tot2=roo[i].to;
		if(find(tot1)==find(tot2)) continue;
		ans+=roo[i].cost;
		if(ans>=AC) return;
		fa[find(tot1)]=find(tot2);
		cho++;
	}
	AC=min(AC,ans);
	return;
}
inline void dfs(int step){
	if(step==k+1){
		init();
		kruskal();
		return;
	}
	dfs(step+1);
	fix[step]=1;
	dfs(step+1);
	fix[step]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		ro[++cnt0].from=a,ro[cnt0].to=b,ro[cnt0].cost=c;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&fi[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&co[i][j]);
	}
	dfs(1);
	cout<<AC;
	return 0;
}
