#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,f[200005],ans=9e18,c[15],b[15][100005],a2[15];
struct node{
	long long u,v,w;
}a[2100005],d[2100005];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long find(long long x){
	if (f[x]==x) return x;
	return f[x]=find(f[x]);
}
void g(long long x,long long h[]){
	long long ans1=0,cnt2=cnt,tot=0;
	for (long long i=1;i<=m;i++) d[i]=a[i];
	for (long long i=1;i<=x;i++){
		ans1+=c[h[i]];
		for (long long j=1;j<=n;j++){
			d[++cnt2]=(node){n+i,j,b[h[i]][j]};
		}
	}
	sort(d+1,d+cnt2+1,cmp);
	for (long long i=1;i<=n+x;i++) f[i]=i;
	for (long long i=1;i<=cnt2;i++){
		long long ru=find(d[i].u),rv=find(d[i].v);
		if (ru!=rv){
			f[ru]=rv;
			ans1+=d[i].w;
			tot++;
		}
		if (tot==n+x-1) break;
	}
	ans=min(ans,ans1);
}
void dfs(long long o){
	g(o-1,a2);
	if (o>k) return ;
	for (long long i=a2[o-1]+1;i<=k;i++){
		a2[o]=i;
		dfs(o+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (long long i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[++cnt]={u,v,w};
	}
	for (long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for (long long j=1;j<=n;j++){
			scanf("%lld",&b[i][j]);
		}
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
/*
6 8 0
1 2 2
1 3 2
2 6 3
2 4 1
3 5 3
6 4 7
4 5 6
1 5 70
*/
