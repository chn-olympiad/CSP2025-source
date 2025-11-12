#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int M=5e6+5,N=1e4+5;
const long long inf=1e18;
int n,m,k,fa[M];
long long daan=inf,mp[19][N],c[N];
struct ed{
	int a,b;
	long long w;
	int id;
}e[M];
bool cmp(ed x,ed y){
	return x.w<y.w;
}
bool Cmp(ed x,ed y){
	return x.id<y.id;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool ud[M];
void work1(){
	long long ans=0;
	for(int i=1;i<=m;i++){
		int a,b;
		long long w;
		scanf("%d%d%lld",&a,&b,&w);
		e[i]=(ed){a,b,w,i};
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int faa=find(e[i].a),fab=find(e[i].b);
		if(faa==fab)continue;
		ans+=e[i].w;
		fa[faa]=fab;
	}
	sort(e+1,e+1+m,cmp);
	printf("%lld",ans);
}
void work2(){
	//for(int i=1;i<=k;i++)cout<<ud[i]<<" ud";
	//cout<<"\n";
	int tot=m;
	long long ans=0;
	for(int i=1;i<=k;i++){
		if(!ud[i])continue;
		ans+=c[i];
		for(int j=1;j<=n;j++)
			e[++tot]=(ed){i+n,j,mp[i][j],tot};
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		int faa=find(e[i].a),fab=find(e[i].b);
		if(faa==fab)continue;
		//cout<<e[i].a<<" a"<<e[i].b<<" b"<<e[i].w<<" w\n";
		ans+=e[i].w;
		fa[faa]=fab;
	}
	//cout<<ans<<"\n";
	daan=min(daan,ans);
	sort(e+1,e+1+tot,Cmp);
	return ;
}
void dfs(int x){
	if(x>k){
		work2();
		return ;
	}
	dfs(x+1);
	ud[x]=1;
	dfs(x+1);
	ud[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0){
		work1();
		return 0;
	}
	if(k<=10){
		for(int i=1;i<=m;i++){
			int a,b;
			long long w;
			scanf("%d%d%lld",&a,&b,&w);
			e[i]=(ed){a,b,w,i};
		}
		for(int i=1;i<=k;i++){
			scanf("%lld",&c[i]);
			for(int j=1;j<=n;j++)
				scanf("%lld",&mp[i][j]);
		}
		dfs(1);
		printf("%lld",daan);
		return 0;
	}
	return 0;
} 
