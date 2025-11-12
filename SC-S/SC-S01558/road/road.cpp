#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

typedef long long ll;

const int N=1e4+20,M=1e6+1e5+10,K=12;

int n,m,k;
struct Edge{
	int u,v,w;
	char used;
	bool operator<(const Edge &o)const{
		return w<o.w;
	}
}edges[M],tmp[M],b[M];
struct Node{
	int v,w;
	bool operator<(const Node &o)const{
		return w<o.w;
	}
}a[K][N];
int c[K];
int p[N];
int sz[N];
char Fir;
ll ans=1e18;

void Merge(int l1,int r1,int l2,int r2){
	int cnt=l1-1;
	for(int i=l1,j=l2;i<=r1||j<=r2;)
		if(j>r2||(i<=r1&&edges[i].w<edges[j].w))
			tmp[++cnt]=edges[i++];
		else tmp[++cnt]=edges[j++];
	for(int i=l1;i<=r2;++i) edges[i]=tmp[i];
}
void split(){
	for(int i=1;i<n;++i) edges[i]=b[i];
}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
ll Mst(int m,int S){
	int mm=m;
	for(int i=1;i<=n;++i) p[i]=i,sz[i]=1;
	ll res=0;
	int ccc=n-1;
	for(int i=1;i<=k;++i)if(S<<1>>i&1){
		++ccc;
		res+=c[i];
		if(res>=ans) return ans;
		p[n+i]=n+i;
		sz[n+i]=1;
		for(int j=1;j<=n;++j) edges[++mm]={n+i,a[i][j].v,a[i][j].w,0};
//		Merge(1,l-1,l,r);
	}
	for(int i=mm-n;i>=m;i-=n) Merge((i>m?i-n+1:1),i,i+1,mm);
	ll sum=res;
	for(int i=1;i<=ccc;++i) sum+=edges[i].w;
	if(sum>=ans) return (Fir?split():void()),ans;
	for(int i=1;i<=mm;++i){
		int u=edges[i].u,v=edges[i].v,w=edges[i].w;
		int pu=find(u),pv=find(v);
		if(pu==pv) continue;
		res+=w;
		if(res>=ans) return (Fir?split():void()),ans;
		if(sz[pu]>sz[pv]) pu^=pv^=pu^=pv;
		sz[pu]+=sz[pv];
		p[pu]=pv;
		edges[i].used=1;
	}
	if(Fir) split();
	return res;
}
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int main(){
	Fre("road");
	n=read(),m=read(),k=read();
	for(int i=1,u,v,w;i<=m;++i) u=read(),v=read(),w=read(),edges[i]={u,v,w,0};
	sort(edges+1,edges+m+1);
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j) a[i][j]={j,read()};
		sort(a[i]+1,a[i]+n+1);
	}
//	puts("----------");
	Fir=0;
	ans=Mst(m,0);
	Fir=1;
//	puts("----------");
	int nm=0;
	for(int i=1;i<=m;++i)
		if(edges[i].used)
			edges[++nm]=edges[i];
	for(int i=1;i<n;++i) b[i]=edges[i];
	for(int s=1;s<(1<<k);++s) ans=min(ans,Mst(n-1,s));
	printf("%lld\n",ans);
	
	return 0;
}