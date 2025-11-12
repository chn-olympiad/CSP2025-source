#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int u,v,c;
}a[1000010];
int vis[10010],n,k,m,tot;
bool cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		a[++tot]={u,v,c};
	}
	sort(a+1,a+tot+1,cmp);
	ll ans=a[1].c;
	vis[a[1].u]=vis[a[1].v]=1;
	for(int i=2;i<=n;i++){
		if(vis[a[i].u]&&vis[a[i].v]) continue;
		vis[a[i].u]=vis[a[i].v]=1;
		ans+=a[i].c;
	}
	printf("%lld",ans);
	return 0;
} 
