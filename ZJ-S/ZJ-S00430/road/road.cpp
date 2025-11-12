#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15][10015],d[10015],l[15],now,num,anss=1e18,nn;
struct xx{
	long long u,v,w;
}a[10015];
struct yy{
	long long x,y;
};
vector<yy> b[10015],kk[10015];
bool vis[10015];
void dfs(long long step){
	if(step>k){
		memset(vis,0,sizeof vis);
		nn=n,num=0,now=0;
		for(long long i=1;i<=n;i++)kk[i].clear();
		for(long long i=1;i<=n;i++){
			for(long long j=0;j<b[i].size();j++){
				kk[i].push_back(b[i][j]);
			}
		}
		for(long long i=1;i<=k;i++){
			if(l[i]){
				nn++;
				num+=c[i][0];
				for(long long j=1;j<=n;j++){
					yy ppp,qqq;
					ppp.x=j,ppp.y=c[i][j];
					qqq.x=nn,qqq.y=c[i][j];
					kk[nn].push_back(ppp);
					kk[j].push_back(qqq);
				}
			}
		}
		if(num<anss){
			long long ans=0;
			d[++now]=1;
			vis[1]=true;
			while(now!=nn){
				long long tot=1e18,p;
				for(long long j=1;j<=now;j++){
					for(long long k=0;k<kk[d[j]].size();k++){
						if(!vis[kk[d[j]][k].x]){
							if(kk[d[j]][k].y<tot){
								tot=kk[d[j]][k].y;
								p=kk[d[j]][k].x;
							}
						}
					}
				}
				d[++now]=p;
				vis[p]=true;
				ans+=tot;
				if(ans>=anss)break;
			}
			anss=min(ans+num,anss);
		}
		return ;
	}
	l[step]=1;
	dfs(step+1);
	l[step]=0;
	dfs(step+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
		yy ppp,qqq;
		ppp.x=a[i].v,ppp.y=a[i].w;
		qqq.x=a[i].u,qqq.y=a[i].w;
		b[a[i].u].push_back(ppp);
		b[a[i].v].push_back(qqq);
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i][0]);
		for(long long j=1;j<=n;j++)scanf("%lld",&c[i][j]);
	}
	dfs(1);
	printf("%lld",anss);
	return 0;
}
