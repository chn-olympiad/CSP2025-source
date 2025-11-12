#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const long long N=3e6+5;
int n,m,k;
long long ans=0x3f3f3f3f;
long long fa[N],c[N],r1[15][10005],vis[15];
struct road {
	int u,v;
	long long val,id;
} r[N];
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(road hh,road mm) {
	return hh.val<mm.val;
}
bool cmp1(road hh,road mm) {
	return hh.id<mm.id;
}
void calc(int nn,int cntn) {
	long long ans1=0;
	for(int i=1; i<=10; i++)
		if(vis[i]==1) ans1+=c[i];
	for(int i=1; i<=n+k; i++) fa[i]=i;
	sort(r+1,r+nn+1,cmp);
	for(int i=1; i<=nn; i++) {
		int uu=r[i].u,vv=r[i].v;
		int U=find(uu),V=find(vv);
		if(U!=V) {
			fa[V]=U;
			ans1+=r[i].val;
			cntn--;
		}
		if(cntn==0) break;
	}
	sort(r+1,r+nn+1,cmp1);
	ans=min(ans,ans1);
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		long long x,y,v;
		scanf("%lld%lld%lld",&x,&y,&v);
		r[i]= {x,y,v,i};
	}
	for(int i=1; i<=k; i++) {
		scanf("%lld",&c[i]);
		for(int j=1; j<=n; j++) scanf("%lld",&r1[i][j]);
	}
	for(int i=1; i<=k; i++) {
		if(c[i]!=0) break;
		if(i!=k) continue;
		int top=m;
		for(int ii=1; ii<=k; ii++)
			for(int kk=1; kk<=n; kk++) r[++top]= {n+ii,kk,r1[ii][kk],top};
		for(int ii=1; ii<=k; ii++) vis[ii]=1;
		calc(top,n+k);
		printf("%lld\n",ans);
		return 0;
	}
	int q1=pow(2,k)-1;
	for(int j=0; j<=q1; j++) {
		int qq1=j,num=0,top=m;
		for(int i=0; i<k; i++) {
			vis[i+1]=0;
			if(qq1%2==1) {
				vis[i+1]=1;
				num++;
				for(int kk=1; kk<=n; kk++) r[++top]= {n+i+1,kk,r1[i+1][kk],top};
			}
			qq1/=2;
		}
		calc(top,num+n);
	}
	printf("%lld\n",ans);
	return 0;
}
