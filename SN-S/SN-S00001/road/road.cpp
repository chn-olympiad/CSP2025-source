//丁一宸 SN-S00001 西安高新第一中学
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
namespace DYC{
namespace FastIO{
	const int LEN=1<<20;
	char buf[LEN],obuf[LEN],*p1=buf,*p2=buf,*p3=obuf;
	il char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,LEN,stdin),p1==p2)?EOF:*p1++;}
	il void flush(){fwrite(obuf,1,p3-obuf,stdout),p3=obuf;}
	il void pc(char x){p3-obuf==LEN?flush():void(),*p3++=x;}
	il void read(int &x){
		char ch=gc();x=0;
		while(ch<'0'||ch>'9')ch=gc();
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc();
	}
	il void read(int &x,auto &...y){read(x),read(y...);}
	il void write(ll x){
		short top=0,stk[20];
		do stk[top++]=x%10,x/=10;while(x);
		while(top)pc(stk[--top]|48);
	}
}
using namespace FastIO;

const int N=1e4+15,M=1e6+5,K=10,E=1.1e5+5;
const ll INF=1e18;

int n,m,k,h,t,a[K][N],fa[N],sz[N];
ll ans=INF;
struct Edge{int u,v,w;}edg[M],usd[E];
il int Find(int u){return fa[u]==u?u:fa[u]=Find(fa[u]);}
il void Merge(int u,int v){
	if(sz[u]<sz[v])u^=v^=u^=v;
	fa[v]=u,sz[u]+=sz[v];
}
il void main(){
	read(n,m,k),h=1<<k;
	for(int i=1,u,v,w;i<=m;i++)read(u,v,w),edg[i]={u,v,w};
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	sort(edg+1,edg+1+m,[](Edge x,Edge y){return x.w<y.w;});
	for(int i=1;i<=m&&t<n-1;i++){
		int u=Find(edg[i].u),v=Find(edg[i].v);
		if(u!=v)Merge(u,v),usd[++t]=edg[i];
	}
	for(int i=0;i<k;i++)for(int p=0;p<=n;p++)read(a[i][p]);
	for(int i=0;i<k;i++)for(int p=1;p<=n;p++)usd[++t]={-i,p,a[i][p]};
	sort(usd+1,usd+1+t,[](Edge x,Edge y){return x.w<y.w;});
	for(int S=0;S<h;S++){
		ll sum=0;
		for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
		for(int i=0;i<k;i++)if(S>>i&1)sum+=a[i][0];
		for(int i=1;i<=t;i++){
			int u=usd[i].u,v=usd[i].v;
			if(u<=0&&(~S>>(-u)&1))continue;
			if((u=Find(u>0?u:n-u+1))!=(v=Find(v)))Merge(u,v),sum+=usd[i].w;
		}
		ans=min(ans,sum); 
	}
	write(ans),flush();
}}
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	DYC::main();
}
