#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
using namespace std;
const int inf=0x3f3f3f3f,N=4e5+5,M=2e6+5;
int n,m,k,head[M],cnt=1,fa[N];
struct node{
	int fr,to,nxt;
	ll w;
}edge[M<<1];
bool cmp(node aa,node bb){
	return aa.w<bb.w;
}
void add(int u,int v,int k){
	edge[cnt].to=v;
	edge[cnt].fr=u;
	edge[cnt].w=k;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
}
int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
ll K(){
	int cnt=0;
	ll ans=0;
	n+=k;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i;++i){
		if(!edge[i].fr) break;
		int x=edge[i].fr,y=edge[i].to;
		int xx=Find(x),yy=Find(y);
		if(xx==yy) continue;
		ans+=edge[i].w,cnt++;
		fa[xx]=yy;
	}
	if(cnt!=n-1) return -1;
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v;
	ll w;
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}m<<=1;
	if(!k){
		printf("%lld",K());
		return 0;
	}
	for(int i=1;i<=k;i++){
		int x,y;
		scanf("%d",&x);
		for(int j=1;j<=n;j++){
			scanf("%d",&y);
			add(i+n,j,y);
			add(j,i+n,y);
			m+=2;
		}
	}printf("%lld",K());
	return 0;
}
