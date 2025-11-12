#include<iostream>
#include<algorithm>
using namespace std;
const int N=10044,M=1600066;
struct Ed{
	int u,v,w;
	int operator<(Ed y){return w<y.w;}
};Ed e[M];
int fa[N],c[23],a[23][N];
int fnd(int x){
	if(fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,g=0;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){int u,v,w;scanf("%d%d%d",&u,&v,&w);e[i]={u,v,w};}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);int t0=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);if(!a[i][j])t0=j;
		}
		if(c[i]==0&&t0)for(int j=1;j<=n;j++)if(j!=t0)e[++m]={t0,j,a[i][j]};
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	long long ans=0;
	for(int i=1;i<=m&&g<n-1;i++)
		if(fnd(e[i].u)!=fnd(e[i].v))ans+=e[i].w,fa[fnd(e[i].u)]=fnd(e[i].v),g++;
	printf("%lld",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}/*1~4+8A,4*12=48pts*/
