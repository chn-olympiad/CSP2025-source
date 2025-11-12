#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5,M=3e6+5;
int n,m,k;
int fa[N];
ll sum;
struct edge{
	ll u,v,w;
}e[M],e2[M];

int getfa(int u){
	if(fa[u]==u) return u;
	return fa[u]=getfa(fa[u]);
}

struct point{
	ll c;
	ll a[N];
}p[15];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
ll ans;
void work1(){
	int cnt=0;
	ans=0;
	for(int i=1;i<=m;i++){
		if(cnt>=n-1 ) break;
//		printf("%lld %lld\n",e[i].u,e[i].v);
		int faa=getfa(e[i].u),fab=getfa(e[i].v);
		if(faa==fab) continue;
		cnt++;
		ans+=e[i].w;
		fa[faa]=fab;
	}
	printf("%lld\n",ans);
}

ll work(ll tmp){
//	ll tmp=0;
	sort(e2+1,e2+m+1,cmp);
	
	for(int i=1;i<=n+100;i++) fa[i]=i;
	int cnt=0;
//	ll ans=0;
	for(int i=1;i<=m;i++){
		if(sum!=0 && tmp>=sum) return tmp;
//		if(cnt>=n-1 ) break;
//		printf("%lld %lld\n",e[i].u,e[i].v);
		int faa=getfa(e2[i].u),fab=getfa(e2[i].v);
		if(faa==fab) continue;
		cnt++;
		tmp+=e2[i].w;
		fa[faa]=fab;
	}
	return tmp;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	int initn=n;

	for(int i=1;i<=n+k+5;i++) fa[i]=i;
	
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
		
	}
	int idx=0;
	int nown=n;
	for(int i=1;i<=k;i++){
		
		ll c;
		scanf("%lld",&c);
		if(c==0){
			nown++;
			for(int j=1;j<=initn;j++){
				ll tmp;
				scanf("%lld",&tmp);
				m++;
				e[m].u=j;
				e[m].v=nown;
				e[m].w=tmp;
			}
		}else{
			idx++;
			p[idx].c=c;
			for(int j=1;j<=n;j++){
				scanf("%lld",&p[idx].a[j]);
			}
		}
	}
	
	n=nown;
	if(idx==0){
		sort(e+1,e+m+1,cmp);
		work1();
		return 0;
	}
	int t=(1<<idx)-1;
//	printf("%lld\n",idx);
	int yuanm=m,yuann=n;
//	printf("%d\n",yuanm);
	for(int j=1;j<=m;j++){
			e2[j].u=e[j].u;
			e2[j].v=e[j].v;
			e2[j].w=e[j].w;
		}
	sum=work(0);
	for(int i=1;i<=t;i++){
		m=yuanm;n=yuann;
		for(int j=1;j<=m;j++){
			e2[j].u=e[j].u;
			e2[j].v=e[j].v;
			e2[j].w=e[j].w;
		}
		ans=0;
		for(int j=0;j<idx;j++){
			if(i&(1<<(j))){//printf("%lld\n",j);
				ans+=p[j+1].c;
				n++;
				for(int l=1;l<=initn;l++){
					m++;
					e2[m].u=n;
					e2[m].v=l;
					e2[m].w=p[j+1].a[l];
				}
			}
		}
		if(ans>=sum) continue;
		sum=min(sum,work(ans));
	}
	printf("%lld\n",sum);
	
	return 0;
}
// 16:10 ducuotile
//17:06 baoli
