#include<bits/stdc++.h>
using namespace std;
const int N=10025,M=1e6+5,K=15;
int n,m,k,c[K],fa[N],tot,change[N],_i[K];
long long ans=2e18;
bool rpp;
struct Road{int u,v,w;}a[K][M];
inline int read(){
	int c=getchar(),now=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))now=now*10-'0'+c,c=getchar();
	return now;
}
inline bool cmp(Road x,Road y){return x.w<y.w;}
inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
inline bool check(int kk,long long C){
	long long now=C;
	int cnt=0;
	for(int i=0;i<=kk;i++)_i[i]=1;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	while(cnt+1<n+kk){
		int Mini=0;
		if(_i[0]==m)Mini=1;
		for(int i=1;i<=kk;i++)
			if(_i[i]<=n&&a[change[i]][_i[i]].w<a[change[Mini]][_i[Mini]].w)
				Mini=i;
		int x=Find(a[change[Mini]][_i[Mini]].u),y=Find(a[change[Mini]][_i[Mini]].v);
		if(x!=y)fa[x]=y,now+=a[change[Mini]][_i[Mini]].w,cnt++;
		_i[Mini]++;
		if(now>=ans)return 0;
	}ans=now;
	return 1;
}
inline void dfs(const int kk,const int t,const long long C){
	if(C>=ans)return;
	if(t==k+1)return;
	if(check(kk-1,C)==0)return;
	for(int i=t;i<=k;i++)change[kk]=i,dfs(kk+1,i+1,C+c[i]);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)a[0][i].u=read(),a[0][i].v=read(),a[0][i].w=read();
	sort(a[0]+1,a[0]+m+1,cmp);
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i])rpp=1;
		for(int j=1;j<=n;j++){
			a[i][j].u=n+i,a[i][j].v=j,a[i][j].w=read();
			if(a[i][j].w)rpp=1;
		}sort(a[i]+1,a[i]+n+1,cmp);
	}
	if(rpp==0)puts("0");
	else dfs(1,1,0),printf("%lld",ans);
	return 0;
}
