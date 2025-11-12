#include<bits/stdc++.h>
using namespace std;
struct node{int d1,d2,val;};
node G[4000005];
bool cmp(node x,node y){
	return x.val<y.val;
}
int father[2000005],c[15];
int getfa(int u){
	if(father[u]==u) return u;
	return father[u]=getfa(father[u]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,now=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		now++,G[now].d1=u,G[now].d2=v,G[now].val=w;
	}
	if(k==0){
		sort(G+1,G+now+1,cmp);
		for(int i=1;i<=n;i++) father[i]=i;
		int ks=n;
		long long ans=0;
		for(int i=1;i<=now;i++){
			if(ks==1) break;
			int af=getfa(G[i].d1),bf=getfa(G[i].d2);
			if(af!=bf) ks--,father[af]=bf,ans+=G[i].val;
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			int w;
			scanf("%d",&w);
			now++,G[now].d1=n+i,G[now].d2=j,G[now].val=w;
		}
	}
	sort(G+1,G+now+1,cmp);
	for(int i=1;i<=n+k;i++) father[i]=i;
	int ks=n;
	long long ans=0;
	for(int i=1;i<=now;i++){
		if(ks==1) break;
		int af=getfa(G[i].d1),bf=getfa(G[i].d2);
		if(af!=bf){
			if(af<=n&&bf<=n) ks--;
			father[af]=bf,ans+=G[i].val;
		}
	}
	printf("%lld\n",ans);
	return 0;
}