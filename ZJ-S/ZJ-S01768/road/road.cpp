#include<bits/stdc++.h>
using namespace std;
struct n1{
	int x,y,z;
}ji[1000009],he[30009],bei[10029][12];
inline bool cnp(n1 x,n1 y){
	return x.z<y.z;
}
int fa[10049];
inline int gf(int x){
	if(fa[x]==x) return x;
	return fa[x]=gf(fa[x]);
}
int tp;
long long ans=0;
int c[19],d[10009][12];long long sum;int n,m,k;
inline void dfs(int kk,long long co){
	if(kk==k+1) {
		ans=min(ans,sum+co);return;
	}
	for(int i=1;i<=tp;i++) bei[i][kk]=he[i];int la=tp;
	dfs(kk+1,co);
	sum=0;
	for(int i=1;i<=n+10;i++) fa[i]=i;
	for(int i=1;i<=n;i++) he[++tp]={n+kk,i,d[i][kk]};
	sort(he+1,he+tp+1,cnp);
	int ks=tp;tp=0;int xx,yy;
	for(int i=1;i<=ks;i++){
		xx=gf(he[i].x),yy=gf(he[i].y);
		if(xx!=yy){
			sum+=((long long)(he[i].z));
			fa[xx]=yy;
			he[++tp]=he[i];
		}
	}
	dfs(kk+1,co+((long long)(c[kk])));
	tp=la;
	for(int i=1;i<=tp;i++) he[i]=bei[i][kk];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;int x,y,z;
	for(int i=1;i<=n+2;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		ji[i]={x,y,z};
	}
	
	sort(ji+1,ji+m+1,cnp);
	for(int i=1;i<=m;i++){
		int xx=gf(ji[i].x),yy=gf(ji[i].y);
		if(xx!=yy){
			he[++tp]=ji[i];
			fa[xx]=yy;
			ans+=(long long)(ji[i].z);
		}
	}
	sum=ans;
	for(int i=1;i<=k;i++){
		int x;scanf("%d",&x);c[i]=x;
		for(int j=1;j<=n;j++){
			scanf("%d",&x);d[j][i]=x;
		}
	}
	dfs(1,0);cout<<ans<<'\n';
	return 0;
}

