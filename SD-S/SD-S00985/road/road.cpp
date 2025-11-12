#include<bits/stdc++.h>
using namespace std;
struct Info{
	int u,v,w;
	friend bool operator < (const Info &A,const Info &B){
		return A.w<B.w;
	}
}b[1100011],e[1100011];
int n,m,k,a[11][10011],c[11],dm,dn,d[11],f[10011];
long long ans=LLONG_MAX;
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
long long solve(){
	for(int i=1;i<=m;i++)e[i]=b[i];
	sort(e+1,e+1+m);
	for(int i=1;i<=n;i++)f[i]=i;
	long long res=0;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			f[u]=v;
			res+=e[i].w;
		}
	}
	return res;
}
inline void dfs(int x){
	if(x==k+1){
		m=dm;n=dn;
		int cnt=0;
		long long sum=0;
		for(int i=1;i<=k;i++)
			if(d[i]){
				cnt++;
				for(int j=1;j<=n;j++)
					b[++m]={cnt+n,j,a[i][j]};
				sum+=c[i];
			}
		n+=cnt;
		sum+=solve();
		ans=min(ans,sum);
		return;
	}
	d[x]=1;
	dfs(x+1);
	d[x]=0;
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
	bool flag=1;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i])flag=0;
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	dm=m;
	dn=n;
	if(flag){
		int cnt=0;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				b[++m]={i+n,j,a[i][j]};
		n+=k;
		printf("%lld\n",solve());
		return 0;
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
