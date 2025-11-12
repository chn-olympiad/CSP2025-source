#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
struct edge{
	int u,v,w;
}e[N],used[N];
int c[15],a[15][N];
ll ans,sum;
int n,m,k,fa[N];
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x),y=get(y);
	fa[x]=y;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll solve(int v){
	int cc=n,cnt=n-1;sum=0;
	for(int i=1;i<n;i++) e[i]=used[i];
	for(int i=1;i<=k;i++){
		if(v>>(i-1)&1){
			cc++,sum+=c[i];
			for(int j=1;j<=n;j++) e[++cnt]={cc,j,a[i][j]};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cc;i++) fa[i]=i;
	int tot=0;
	for(int i=1;i<=cnt;i++){
		if(tot==cc-1) break;
		if(get(e[i].u)!=get(e[i].v)){
			sum+=e[i].w,tot++;
			merge(e[i].u,e[i].v);
		}
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	int tot=0;
	for(int i=1;i<=n;i++) fa[i]=i; 
	for(int i=1;i<=m;i++){
		if(tot==n-1) break;
		if(get(e[i].u)!=get(e[i].v)){
			used[++tot]=e[i];
			merge(e[i].u,e[i].v);
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	ans=1e18;
	for(int i=0;i<(1<<k);i++) 
		ans=min(ans,solve(i));
	cout<<ans;
	return 0;
}