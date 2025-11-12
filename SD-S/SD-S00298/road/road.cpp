#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+100,M=1e6+10;
struct node{
	int u,v,w;
}a[M],b[M];
int n,m,k;
int fa[N],tot,siz[N];
int c[N],flag[N];
long long ans,now;
bool cmp(node x,node y){
	return x.w<y.w;
}
int read(){
	char c=getchar();
	int re=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) re=(re<<1)+(re<<3)+c-'0';
	return re;
}
int findfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) a[i]=node{read(),read(),read()};
	for(int i=1;i<=n;i++) flag[i]=1,fa[i]=i,siz[i]=1;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fu=findfa(a[i].u),fv=findfa(a[i].v);
		if(fu==fv) continue;
		if(siz[fu]<siz[fv]) swap(fu,fv);
		siz[fu]+=siz[fv];
		fa[fv]=fu;
		b[++tot]=a[i];
		ans+=a[i].w;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) b[++tot]=node{i+n,j,read()};
	}
	sort(b+1,b+1+tot,cmp);
	for(int i=1;i<(1<<k);i++){
		now=0;
		for(int j=0;j<k;j++){
			if((1<<j)&i) now+=c[j+1],flag[j+n+1]=1;
			else flag[j+n+1]=0;
		}
		if(now>=ans) continue;
		for(int j=1;j<=n+k;j++) fa[j]=j,siz[j]=1;
		for(int j=1;j<=tot;j++){
			if((flag[b[j].u]&&flag[b[j].v])!=1) continue;
			int fu=findfa(b[j].u),fv=findfa(b[j].v);
			if(fu==fv) continue;
//			if(now+b[j].w>=ans) break;//如果真这样写，这里会出bug！ 
			now+=b[j].w;
			if(now>=ans) break;
			if(siz[fu]<siz[fv]) swap(fu,fv);
			siz[fu]+=siz[fv];
			fa[fv]=fu;
		}
		ans=min(ans,now);
	}
	printf("%lld",ans);
	return 0;
}
