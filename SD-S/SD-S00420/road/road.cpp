#include <bits/stdc++.h>
using namespace std;
const int N=2e4+5,M=2e6+5;
struct edge{
	int u,v,w,op;
}e[M];
int n,m,k,c[N],fa[N],dep[N],cnt=0;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool cmp(edge A,edge B){
	return A.w<B.w;
}
int merge(int x,int y){
	x=find(x),y=find(y);
//	printf("%d %d\n",x,y);
	if(x==y) return 0;
	if(dep[x]>dep[y]) swap(x,y);
	fa[x]=y;
	if(dep[x]==dep[y]) ++dep[y];
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].op=0;
	}
	cnt=m;
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j){
			int x; scanf("%d",&x);
			++cnt;
			e[cnt].u=i+n,e[cnt].v=j,e[cnt].w=x;
			e[cnt].op=i;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	long long ans=1e18;
	for(int i=1;i<=n+k;++i) fa[i]=i,dep[i]=1;
	for(int S=0;S<(1<<k);++S){
		int flg=0,num=n-1;
		long long tmp=0;
		for(int i=1;i<=k;++i){
			if((S>>(i-1))&1) ++num,tmp+=(long long)c[i];
		    if(c[i]==0&&((S>>(i-1))&1)==0){
			    flg=1; break;
			}
		}
		if(flg) continue;
		for(int i=1;i<=n+k;++i) fa[i]=i,dep[i]=1;
		for(int i=1;i<=cnt;++i) if(e[i].op==0 || ((S>>(e[i].op-1))&1)==1){
//			printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
			if(merge(e[i].u,e[i].v)){
				--num;
				tmp+=(long long)e[i].w;
				if(num<=0) break;
			}
		}
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}
