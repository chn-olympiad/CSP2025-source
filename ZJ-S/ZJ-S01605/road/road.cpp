#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+4,M=2e6+6;
const ll inf=1e18+7;

int n,m,k,c[13],a[13][N],fa[N];
ll ans=inf;
bool b[13];
struct node{
	int u,v,w;
}side[M];
node s[M];
bool cmp(node x,node y){
	return x.w<y.w;
}

int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}

void solve(ll sum){
	int cnt=m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) s[i]=side[i];
	for(int i=1;i<=k;i++){
		if(b[i]){
			for(int j=1;j<=n;j++) s[++cnt]={i,j,a[i][j]};
			sum+=c[i];
		}
			
	}
	sort(s+1,s+cnt+1,cmp);
	int pts=0;
	for(int i=1;i<=cnt;i++){
		if(find(s[i].u)==find(s[i].v)) continue;
		sum+=s[i].w;
		pts++;
//		printf("%d:%d\n",pts,s[i].w);
		merge(s[i].u,s[i].v);
		if(pts>=n-1) break;
	}
//	printf("%lld\n",sum);
	ans=min(ans,sum);
}

void dfs(int flr,ll x){
	if(flr>k){
		solve(x);
		return;
	}
	x+=c[flr];
	b[flr]=true;
	dfs(flr+1,x);
	x-=c[flr];
	b[flr]=false;
	dfs(flr+1,x);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		side[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}