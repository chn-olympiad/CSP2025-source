#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,inf=1e18,mod=1e9+7,M=1e6+10;
int read(){
	int x;
	scanf("%lld",&x);
	return x;
}
void write(int x){
	printf("%lld",x);
}
void writeh(int x){
	printf("%lld",x);
	putchar('\n');
}
void writek(int x){
	printf("%lld",x);
	putchar(' ');
}
int n,m,k,c[15],a[15][N],fa[N],ans=inf;
bool flag;
struct edge{
	int u,v,w;
	friend bool operator < (edge x,edge y){
		return x.w>y.w;
	}
};
edge e[M];
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int u,int v){
	u=find(u); v=find(v);
	if(u!=v) fa[u]=v;
}
int spfa(int st){
	priority_queue <edge> q;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) q.push(e[i]);
	for(int i=1;i<=k;i++){
		if(st&(1ll<<i)){
			for(int j=1;j<=n;j++){
				for(int p=1;p<=n;p++){
					if(j!=p) q.push((edge){j,p,a[i][j]+a[i][p]});
				}
			}
		}
	}
	int cnt=0,sum=0;
	for(int i=1;i<=k;i++){
		if(st&(1ll<<i)) sum+=c[i];
	}
	while(!q.empty()){
		edge x=q.top(); q.pop();
		int u=x.u,v=x.v;
		u=find(u); v=find(v);
		if(u!=v){
			cnt++;
			merge(u,v);
			sum+=x.w;
		}
		if(cnt==n-1) break;
	}
	return sum;
}
void dfs(int pos,int st){
	if(pos==k+1){
		ans=min(ans,spfa(st));
		return ;
	}
	dfs(pos+1,st|(1ll<<pos));
	dfs(pos+1,st);
}
int spfa2(){
	priority_queue <edge> q;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) q.push(e[i]);
	int cnt=0,sum=0;
	while(!q.empty()){
		edge x=q.top(); q.pop();
		int u=x.u,v=x.v;
		u=find(u); v=find(v);
		if(u!=v){
			cnt++;
			merge(u,v);
			sum+=x.w;
		}
		if(cnt==n-1) break;
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=1;i<=m;i++){
		e[i]=(edge){read(),read(),read()};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]) flag=1;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]) flag=1;
		}
	}
	if(!flag){
		write(spfa2());
		return 0;
	}
	dfs(1,0);
	write(ans);
	return 0;
}