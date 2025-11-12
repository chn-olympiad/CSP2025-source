#include<stdio.h>
#include<algorithm>
#include<string.h>
const int N=1.5e4+5,M=3e6+5;
typedef long long ll;
struct edge{
	ll from,to,w;
};
namespace{
	ll n,m,k,cts[15],vis[N][N],idx=0,ans=0,cur=1,ctc[15][N];
	edge e[M];
}
void add(int u,int v,int w){
	e[++idx].from=u,e[idx].to=v,e[idx].w=w;
}
bool check(){
	for(int i=2;i<=n;i++) if(!vis[1][i]) return 0;
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&cts[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&ctc[i][j]);
	}
	std::sort(e+1,e+1+idx,[](edge &a,edge &b){return a.w==b.w? a.from<b.from:a.w<b.w;});
	while(1){
		if(check()) break;
		if(e[cur].from>n){cur++;continue;}
		else if(e[cur].to>n){cur++;continue;}
		else{
			if(vis[e[cur].from][e[cur].to]||vis[e[cur].to][e[cur].from]){cur++;continue;}
			ans+=e[cur].w;
			vis[e[cur].from][e[cur].to]=1,vis[e[cur].to][e[cur].from]=1;
			for(int j=1;j<=n;j++) if(vis[e[cur].from][j]) vis[e[cur].to][j]=1,vis[j][e[cur].to]=1;
			for(int j=1;j<=n;j++) if(vis[j][e[cur].to]) vis[e[cur].from][j]=1,vis[j][e[cur].from]=1;
			cur++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}