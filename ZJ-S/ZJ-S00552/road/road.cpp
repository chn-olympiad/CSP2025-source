#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,a[12],f[10100],h[10100],s,t,p,w,x,y,ans=1e17;
struct vt{int u,v,w;}g[1000005],e[100005],r[100005];
inline bool cmp(vt a,vt b){return a.w<b.w;}
inline int find(int u){
	if(f[u]==u)return u;
	return f[u]=find(f[u]);
}
main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&g[i].u,&g[i].v,&g[i].w);
	for(int i=0;i<k;i++){
		scanf("%lld",&a[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&e[++w].w);
			e[w].u=i+n+1,e[w].v=j;
		}
	}
	sort(g+1,g+m+1,cmp),sort(e+1,e+w+1,cmp);
	g[m+1].w=1e18;
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++)f[j]=j,h[j]=1;
		s=0,t=0,p=n-1;
		for(int j=0;j<k;j++)if(i&(1<<j))s+=a[j],p++;
		for(int j=1;j<=w;j++)if(i&(1<<(e[j].u-n-1)))r[++t].u=e[j].u,r[t].v=e[j].v,r[t].w=e[j].w;
		r[t+1].w=1e18;
		for(int j=0,l=0;j<=m,l<=t;)if(g[j+1].w<r[l+1].w){
			j++,x=find(g[j].u),y=find(g[j].v);
			if(x==y)continue;
			s+=g[j].w;
			if(h[x]<h[y])swap(x,y);
			if(h[x]==h[y])h[x]++;
			f[y]=x,p--;
			if(!p)break;
		}
		else{
			l++,x=find(r[l].u),y=find(r[l].v);
			if(x==y)continue;
			s+=r[l].w;
			if(h[x]<h[y])swap(x,y);
			if(h[x]==h[y])h[x]++;
			f[y]=x,p--;
			if(!p)break;
		}
		ans=min(ans,s);
	}
	printf("%lld",ans);
}
