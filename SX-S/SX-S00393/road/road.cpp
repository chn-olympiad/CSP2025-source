#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
int c[15];
int f[15][N];
int fa[N<<1];
struct road{
	int u,v,w;
}s[M<<1];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
long long ans=LONG_LONG_MAX;
void work(int x){
	long long sum=0,tot=0;
	for(int i=0;i<=k;++i){
		if((x>>i)&1){
			sum+=c[i+1];
			for(int j=1;j<=n;++j){
				tot++;
				s[m+tot]={n+i+1,j,f[i+1][j]};
			}
		}
	}
	for(int i=1;i<=n+k;++i) fa[i]=i;
	sort(s+1,s+m+tot+1,[](road a,road b){return a.w<b.w;});
	for(int i=1;i<=m+tot;++i){
		int a=find(s[i].u),b=find(s[i].v);
		if(a==b) continue;
		fa[b]=a;
		sum+=s[i].w;
	}
	ans=min(ans,sum);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>s[i].u>>s[i].v>>s[i].w;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>f[i][j];
		}
	}
	for(int i=0;i<(1<<k);++i) work(i);
	cout<<ans<<'\n';
	return 0;
}
