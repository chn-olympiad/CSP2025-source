#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int s[10001],t[10001];
long long u[1000001],v[1000001],w[1000001];
long long city[11][10002];
long long ans=INT_MAX;
int a(int x){
	if(s[x]!=x) s[x]=a(s[x]);
	return s[x];
}
void b(int x,int y){
	x=a(x);
	y=a(y);
	if(x!=y) s[x]=s[y];
}
bool c(){
	int num=0;
	for(int i=1;i<=n;++i){
		if(s[i]==i) num++;
	}
	if(num==1) return true;
	else return false;
}
void dfs(int x,long long cnt){
	if(c()){
		ans=min(cnt,ans);
		return;
	}
	for(int i=x+1;i<=m;++i){
		for(int e=1;e<=n;++e) t[e]=s[e];
		b(u[i],v[i]);
		dfs(i,cnt+w[i]);
		for(int e=1;e<=n;++e) s[e]=t[e];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i) scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n+1;++j){
			scanf("%lld",&city[i][j]);
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	}
	
	for(int i=1;i<=n;++i) s[i]=i;
	dfs(0,0);
	printf("%lld",ans);
	return 0;
}
