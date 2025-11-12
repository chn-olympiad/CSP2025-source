#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int n,m,k,fa[N];
ll a[15],c[15][N],ans,cnt,mx;
struct qwq{ll a,b,l;}x[N*1100];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k,iota(fa+1,fa+n+1,1);
	for(int i=1;i<=m;++i)cin>>x[i].a>>x[i].b>>x[i].l,mx=max(mx,x[i].l);
	for(int i=1;i<=k;++i){
		cin>>a[i],cnt+=a[i];
		for(int j=1;j<=n;++j)cin>>c[i][j];
	}if(!cnt){
		cnt=m;
		for(int i=1;i<=k;++i)for(int j=1;j<n;++j)for(int l=j+1;l<=n;++l)if(c[i][j]+c[i][l]<=mx)x[++cnt]={j,l,c[i][j]+c[i][l]};
		sort(x+1,x+cnt+1,[](qwq x,qwq y){return x.l<y.l;});
		for(int i=1;i<=cnt;++i){
			int u=find(x[i].a),v=find(x[i].b);
			if(u!=v)fa[u]=v,ans+=x[i].l;
		}cout<<ans;
	}else{
		sort(x+1,x+m+1,[](qwq x,qwq y){return x.l<y.l;});
		for(int i=1;i<=m;++i){
			int u=find(x[i].a),v=find(x[i].b);
			if(u!=v)fa[u]=v,ans+=x[i].l;
		}cout<<ans;
	}return 0;
}
