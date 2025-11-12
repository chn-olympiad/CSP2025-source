#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10,M=1e6+10,K=20;
int n,m,k,a[K];
ll c[K],f[N],ans=LLONG_MAX;
int cnt;
struct edge{
	int u,v;
	ll l;
}E[M+N*K];
bool cmp(edge x,edge y){
	return x.l<y.l;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
ll kruskal(){
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	ll res=0,b=0;
	for(int i=1;i<=k;i++){
		res+=a[i]*c[i];
		b+=a[i];
		if(res>=ans){
			return LLONG_MAX;
		}
	}
	for(int i=1,c=0;c<n+b-1;i++){
		int u=E[i].u,v=E[i].v,l=E[i].l;
		if(u>n){
			if(!a[u-n]) continue;
		}
		if(find(u)==find(v)){
			continue;
		}
		res+=l;
		if(res>=ans) return LLONG_MAX;
		merge(u,v);
		c++;
	}
	return res;
}
void dfs(int x){
	if(x>k){
		ans=min(ans,kruskal());
		return ;
	}
	a[x]=1;
	dfs(x+1);
	a[x]=0;
	dfs(x+1);
}
int readi(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int readl(){
	ll x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=readi();m=readi();k=readi();
	for(int i=1;i<=m;i++){
		int u,v;
		ll l;
		u=readi();v=readi();l=readl();
		E[++cnt]={u,v,l};
	}
	for(int i=1;i<=k;i++){
		c[i]=readl();
		for(int j=1;j<=n;j++){
			ll l;
			l=readl();
			E[++cnt]={i+n,j,l};
		}
	}
	sort(E+1,E+cnt+1,cmp);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
