#include<bits/stdc++.h>
#define il inline
#define int long long
#define pii pair<int,int>
#define mk make_pair
#define fir first
#define sec second
#define put putchar
using namespace std;
il int rd(){
	int sum=0,p=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+(ch-'0');ch=getchar();}
	return sum*p;
}
il void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=2e6+10,M=1e4+10;
struct node{
	int u,v,w;
}e[N],g[N];
int n,m,k,a[11][M],c[11],ans=JYAAKIOI,tot,fa[N];
bool vis[M];
il bool cmp(node x,node y){return x.w<y.w;}
il int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
il void ck(){
	tot=m;
	int res=0;
	for(int i=1;i<=tot;++i)e[i]=g[i];
	for(int i=1;i<=k;++i){
		if(vis[i]){
			res+=c[i];
			for(int j=1;j<=n;++j){
				for(int k=j+1;k<=n;++k){
					e[++tot]={j,k,a[i][j]+a[i][k]};
				}
			}
		}
	}
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;++i){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		fa[v]=u;
		res+=e[i].w;
	}
	ans=min(ans,res);
}
il void dfs(int x){
	if(x>k){
		ck();
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();m=rd();k=rd();
	for(int i=1;i<=m;++i){g[i].u=rd();g[i].v=rd();g[i].w=rd();}
	for(int i=1;i<=k;++i){
		c[i]=rd();
		for(int j=1;j<=n;++j)a[i][j]=rd();
	}
	dfs(1);
	wr(ans);
	return 0;
}
