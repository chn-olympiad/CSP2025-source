#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
const int M=1e4+15;
int n,m,k,a[15][M],c[15],tot,top,fa[M],flag[15],tot2,vis[15];
struct node{
	long long u,v,id,idv=0;
	long long w;
}e[N],po[15],ee[N];
long long ans=0;
long long cmp(node s,node t){
	return long(s.w)<long(t.w);
}
int Find(int x){
	if(fa[x]==0) return fa[x]=x;
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
		e[i].id=0;
	}
	tot=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
		for(int j=1;j<=n;j++){
			for(int jj=j+1;jj<=n;jj++){
				long long ww=a[i][j]+a[i][jj]+c[i];
				e[++tot].u=j;
				e[tot].v=jj;
				e[tot].w=ww;
				e[tot].id=i;
				e[tot].idv=c[i];
			}
		}
	}
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		if(e[i].id&&!vis[e[i].id]){
			vis[e[i].id]=i;
			po[i]=e[i];
		}
		else if(e[i].id){
			//cout<<e[i].w<<" "<<e[i].idv<<"\n";
			e[i].w-=e[i].idv;
			ee[++tot2]=e[i];
		}
		else{
			ee[++tot2]=e[i];
		}
	}
	sort(ee+1,ee+1+tot2,cmp);
	int goa=n-1,ff=0,ii=1;
	for(int i=1;i<=tot;i++,ii++){
		node uu=ee[ii];
		for(int j=1;j<=k;j++){
			if(i==vis[j]){
				ii--;
				uu=po[j];
				break;
			}
		}
		int xx=Find(uu.u);
		int yy=Find(uu.v);
		if(xx==yy) continue;
		fa[xx]=yy;
		ans+=uu.w;
		top++;
		if(uu.id!=0){
			goa++;
		}
		if(top==goa){
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
