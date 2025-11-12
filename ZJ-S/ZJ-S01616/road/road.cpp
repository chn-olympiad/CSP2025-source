#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxe=1000005,maxn=10005,maxk=15;
int n,m,k,ans=(long long)1<<60,bt[maxn],fa[maxn];
bool u[maxn];
struct ZS{
	int x,y,w,v;
	bool operator<(const ZS&B)const{
		return w<B.w;
	}
}e[maxe*2];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
int Get(int x){
	if(fa[x]==x) return x;
	return fa[x]=Get(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();u[0]=1;
	for(int i=1;i<=m;i++) 
		e[i]=(ZS){read(),read(),read(),0};
	for(int i=1;i<=k;i++){
		bt[i]=read();
		for(int j=1;j<=n;j++){
			int x=read();
			e[++m]=(ZS){n+i,j,x,i};
//			printf("%d\n",x);
		}
	}
	sort(e+1,e+m+1);
//	for(int i=1;i<=m;i++) printf("%d ",e[i].w);
//	printf("\n");
	for(int i=0;i<=(1<<k)-1;i++){
		int sum=0,cnt=0,N=n;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=k;j++)
			if((i>>j-1)&1) u[j]=1,N++,sum+=bt[j];
			else u[j]=0;
		for(int j=1;j<=m;j++){
			if(!u[e[j].v]) continue;
			int fx=Get(e[j].x),fy=Get(e[j].y);
			if(fx==fy) continue;
			fa[fx]=fy;
			sum+=e[j].w;
			cnt++;
			if(cnt==N-1) break;
		}
//		printf("%lld %lld %lld\n",cnt,N,sum);
		if(cnt==N-1) ans=min(ans,sum);
		if(k==0) break;
	}
	printf("%lld\n",ans);
	return 0;
}