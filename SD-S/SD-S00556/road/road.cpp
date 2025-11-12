#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int N=1e4+10,M=2e6+10;
const ll inf=0x3fffffffffffff;
struct node {
	int u,v,w;
}e[M],te[M];
bool cmp(node x,node y){return x.w<y.w;}
int fa[N],a[N][11],c[11];
int n,k,m;
ll ans=inf;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool flagA=1,vis[11];
void kkk(){
	int tot=0;
	ll tans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v,val=e[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		tot++;
		fa[fx]=fy;
		tans+=val;
		if(tot==n-1)break;
	}
	ans=min(ans,tans);
}
void solveA(){
	int cnt=m,tote=0;
	ll tans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)te[i]=e[i];
	for(int i=1;i<=k;i++){
		int to;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0)to=j;
		}
		for(int j=1;j<=n;j++){
			if(to==j)continue;
			te[cnt+j].u=to,te[cnt+j].v=j,te[cnt+j].w=a[i][j];
		}
		cnt+=n;
	}
	sort(te+1,te+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x=te[i].u,y=te[i].v,val=te[i].w;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		tote++;
		fa[fx]=fy;
		tans+=val;
		if(tote==n-1)break;
	}
	ans=tans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);if(c[i])flagA=0;
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	if(k==0){
		kkk();
		printf("%lld",ans);
		return 0;
	}
	if(flagA){
		solveA();
		printf("%lld",ans);
		return 0;
	}
	int num=1<<k;
	for(int s=0;s<num;s++){
		int cnt=m,tot=0;
		ll tans=0;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=m;i++)te[i]=e[i];
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				tans+=c[i];
				for(int j=1;j<=n;j++){
					te[cnt+j]=node{i+n,j,a[i][j]};
				}
				cnt+=n;
			}
		}
		if(tans>=ans)continue;
		sort(te+1,te+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){		
			int x=te[i].u,y=te[i].v,val=te[i].w;
			int fx=find(x),fy=find(y);
			if(fx==fy)continue;
			fa[fx]=fy;
			tans+=val;
			tot++;
			if(tans>=ans)break;
		}
		ans=min(ans,tans);
	}
	printf("%lld",ans);
	return 0;
}
