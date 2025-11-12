#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e4+5,maxm=2e6+5,inf=1e18;

struct node{
	int u,v,w;
}e[maxm],fk[maxm],l[maxm];

bool cmp(node x,node y){
	return x.w<y.w;
}

int n,m,k,a[15][maxn],c[15];
int fa[maxn],cnt,ans=inf;

int get(int x){
	return fa[x]==x ? x : fa[x]=get(fa[x]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);
//	return 0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=get(u),fv=get(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		fk[++cnt]=e[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
	
	for(int i=0;i<(1<<k);i++){
		memset(l,0,sizeof(l));
		int num=0,tot=0;
		for(int j=1;j<=cnt;j++)l[++tot]=fk[j];
		
		
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				num+=c[j];
				for(int t=1;t<=n;t++)l[++tot]=(node){t,n+j,a[j][t]};
			}
		}
		sort(l+1,l+tot+1,cmp);
		
		for(int j=1;j<=n+15;j++)fa[j]=j;
		
		int flg=0;
		for(int j=i;j;j-=(j&-j))flg--;
		for(int j=1;j<=tot;j++){
			int u=l[j].u, v=l[j].v, w=l[j].w;
			int fu=get(u), fv=get(v);
			if(flg==n-1)break;
			if(fu==fv)continue;
			fa[fu]=fv;
			num+=w;flg++;
		}
		ans=min(num,ans);
	}
	cout<<ans;
	
	
	
	
	
	
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

