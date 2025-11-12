#include<bits/stdc++.h>
using namespace std;
int const N=2e6+5;
long long n,m,k,c[N],d[15][N],cnt1,minn,fa[N];
int gf(int x){
	if(fa[x]==x) return x;
	return fa[x]=gf(fa[x]);
}
struct node{
	long long f,t,v,nee;
}e[N];
bool operator<(const node a,const node b){
	return a.v<b.v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	cnt1=m;minn=(1ll<<60ll);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].f,&e[i].t,&e[i].v);
		e[i].nee=0;
	}
    for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&d[i][j]);
			++cnt1;
			e[cnt1].f=i+n;e[cnt1].t=j;
			e[cnt1].v=d[i][j];
			e[cnt1].nee=i;
		}
	}
	sort(e+1,e+1+cnt1);
	bool s=0;
	for(int i=1;i<=k;i++){
		if(c[i]!=0) s=1; 
	}
	if(s==0){
		long long ansi=0,x=(1<<k)-1;
		bool pd[15];pd[0]=1;
		for(int j=1;j<=k;j++){
			pd[j]=0;
			if(x&1){
				pd[j]=1;
				ansi+=c[j];
			}
			x>>=1;
		}
		for(int j=1;j<=n+k;j++) {
			fa[j]=j;
		}
		for(int j=1;j<=cnt1;j++){
			if(gf(e[j].f)==gf(e[j].t)) continue;
			else if(pd[e[j].nee]==0) continue;
			else{
				ansi+=e[j].v;
				fa[fa[e[j].f]]=e[j].t;
			}
		}
		minn=min(minn,ansi);
	}
	else{
		for(int i=0;i<1<<k;i++){
			long long ansi=0,x=i;
			bool pd[15];pd[0]=1;
			for(int j=1;j<=k;j++){
				pd[j]=0;
				if(x&1){
					pd[j]=1;
					ansi+=c[j];
				}
				x>>=1;
//			printf("%d ",pd[j]);
			}
//		printf("%lld\n",ansi);
			for(int j=1;j<=n+k;j++) {
				fa[j]=j;
			}
			for(int j=1;j<=cnt1;j++){
				if(gf(e[j].f)==gf(e[j].t)) continue;
				else if(pd[e[j].nee]==0) continue;
				else{
					ansi+=e[j].v;
					fa[fa[e[j].f]]=e[j].t;
				}
			}
			minn=min(minn,ansi);
		}	
	}
	printf("%lld\n",minn);
	return 0;
}