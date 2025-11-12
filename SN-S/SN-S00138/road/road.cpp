// 夏菁阳 SN-S00138 西安高新第一中学
#include<bits/stdc++.h>
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define il inline
using namespace std;

char buf[1<<20],*p1=buf,*p2=buf;
il int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return x;
}
using ll=long long;
constexpr int MAXN=1e4+55,MAXM=2e6+5;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,tot,c[11],a[11][MAXN];
struct Edge{
	int u,v;
	ll w;
	il bool operator<(Edge b)const{
		return w<b.w;
	}
}e[MAXM];
int f[MAXN];
il int fnd(int x){
	return f[x]==x?x:f[x]=fnd(f[x]);
}
il ll kruskal(int k=0,int s=0,bool fl=0){
	if(!fl) sort(e+1,e+tot+1);
	iota(f+1,f+n+11,1);
	ll ans=0;
	for(int i=1,cnt=0;i<=tot;i++){
		if(e[i].u>n||e[i].v>n){
			if(!fl) continue;
			if(e[i].u>n&&!(s>>(e[i].u-n-1)&1)) continue;
			if(e[i].v>n&&!(s>>(e[i].v-n-1)&1)) continue;
		}
		int fx=fnd(e[i].u),fy=fnd(e[i].v);
		if(fx==fy) continue;
		f[fy]=fx;
		ans+=e[i].w;
		if(++cnt==n+k-1) break;
	}
	return ans;
}

namespace sb{
	ll fk[1005][1005];
	il int main(){
		memset(fk,0x3f,sizeof fk);
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					fk[j][k]=min(fk[j][k],0ll+a[i][j]+a[i][k]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				e[++tot]={i,j,fk[i][j]};
		printf("%lld\n",kruskal());
		return 0;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i]={read(),read(),read()};
	tot=m;
	if(!k) return printf("%lld\n",kruskal()),0;
	bool fl=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		fl&=!c[i];
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	if(fl&&n<=1e3) return sb::main();
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			e[++tot]={i+n,j,a[i][j]};
	sort(e+1,e+tot+1);
	ll ans=5e18;
	for(int s=0;s<1<<k;s++){
		ll res=0;
		int pc=0;
		for(int i=1;i<=k;i++)
			if(s>>(i-1)&1)
				res+=c[i],pc++;
		ans=min(ans,res+kruskal(pc,s,1));
	}
	printf("%lld\n",ans);
	return 0;
}

