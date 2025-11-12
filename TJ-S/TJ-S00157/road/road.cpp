#include<bits/stdc++.h>

using namespace std;
int n,m,k;
long long c[15];
long long ans=1e9;
struct node{
	int t;
	long long w;
};
vector<node> ct[20005];
void dfs(int u,long long sum,int pd[],int p[],int s){
	if (s>=n){
		ans=min(ans,sum);
		return;
	}
	for (int i=0;i<ct[u].size();i++){
		if (p[ct[u][i].t])continue;
		p[ct[u][i].t]=1;
		if (ct[u][i].t>n){
			if (!pd[ct[u][i].t]){
				sum+=c[ct[u][i].t],pd[ct[u][i].t]=1;
				dfs(ct[u][i].t,sum+ct[u][i].w,pd,p,s);
				sum-=c[ct[u][i].t],pd[ct[u][i].t]=0;
				p[ct[u][i].t]=0;
			}else{
				dfs(ct[u][i].t,sum+ct[u][i].w,pd,p,s);
				p[ct[u][i].t]=0;
			}
			continue;
		}
		if (ct[u][i].t<=n){
			s++;
			dfs(ct[u][i].t,sum+ct[u][i].w,pd,p,s);
			s--;
		}
		p[ct[u][i].t]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		ct[u].push_back({v,w});
		ct[v].push_back({u,w});
	}
	for (int i=n+1;i<=n+k;i++){
		scanf("%lld",&c[i]);
		for (int j=1;j<=n;j++){
			long long w;
			scanf("%lld",&w);
			ct[i].push_back({j,w});
			ct[j].push_back({i,w});
		}
	}
	int pd[20005],p[20005];
	memset(pd,0,sizeof(pd));
	p[1]=1;
	memset(p,0,sizeof(p));
	dfs(1,0,pd,p,1);
	cout<<ans;
	return 0;
}
