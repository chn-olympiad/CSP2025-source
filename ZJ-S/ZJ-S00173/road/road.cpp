#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct edge{
	LL to,nt,val,flag;
}a[3000005];
struct point{
	LL x,y,val;
}p[3000005],p1[3000005];
LL len[15][10005];
LL val[15];
LL n,i,j,k,m,ans=0x7fffffffffffffff,sum=0;
LL nxt[1000005],nxt1[1000005],fa[1000005];
stack<LL> st,st1,st2;
LL father(LL x){
	if(fa[x]==x) return x;
	else return fa[x]=father(fa[x]);
}
LL cmp(point x,point y){
	return x.val<y.val;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].val);
	}
	for(i=1;i<=k;i++){
		scanf("%lld",&val[i]);
		for(j=1;j<=n;j++)
		  scanf("%lld",&len[i][j]);
	}
	for(i=1;i<=n;i++)
	  fa[i]=i;
	sort(p+1,p+m+1,cmp);
	LL cnt=0;
	for(i=1;i<=m;i++)
	  if(father(p[i].x)!=father(p[i].y)){
	  	fa[father(p[i].x)]=father(p[i].y);
	  	sum+=p[i].val;
	  	p1[++cnt].x=p[i].x,p1[cnt].y=p[i].y,p1[cnt].val=p[i].val;
	  }
	ans=min(ans,sum);
	for(i=0;i<(1ll<<k);i++){
	//	printf("%lld\n",ans);
		LL sum1=n-1,sum=0;
		for(j=1;j<=k;j++)
		  if(i&(1ll<<(j-1))){
		  	for(LL x=1;x<=n;x++){
		  		p1[++sum1].x=n+j,p1[sum1].y=x,p1[sum1].val=len[j][x];
			}
			sum+=val[j];
		  }
		sort(p1+1,p1+sum1+1,cmp);
		for(j=1;j<=n+k;j++)
		  fa[j]=j;
		for(j=1;j<=sum1;j++)
		  if(father(p1[j].x)!=father(p1[j].y)){
		  	//printf("%lld %lld %lld\n",sum,p1[j].x,p1[j].y);
		  	fa[fa[p1[j].x]]=fa[p1[j].y];
		  	sum+=p1[j].val;
		  }
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
