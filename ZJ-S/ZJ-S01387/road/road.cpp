#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,sum[1050],fa[10015],k1,cc[12],d[12][10005],ans,t,p;
struct node{
	long long u,v,w;
}a[1000005],b[10005],c[110005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fdfa(int now){
	if(fa[now]==now)return now;
	fa[now]=fdfa(fa[now]);
	return fa[now];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	for(int i=0;i<k;i++){
		scanf("%lld",&cc[i]);
		for(int j=1;j<=n;j++)scanf("%lld",&d[i][j]);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		fdfa(a[i].u);
		fdfa(a[i].v);
		if(fa[a[i].u]!=fa[a[i].v]){
			fa[fa[a[i].v]]=fa[a[i].u];
			sum[0]+=a[i].w;
			b[++k1].u=a[i].u;
			b[k1].v=a[i].v;
			b[k1].w=a[i].w;
		}
	}
	ans=sum[0];
	for(int i=1;i<(1<<k);i++){
		t=n-1;
		for(int j=1;j<n;j++){
			fa[j]=j;
			c[j].u=b[j].u;
			c[j].v=b[j].v;
			c[j].w=b[j].w;
		}
		fa[n]=n;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				fa[n+j+1]=n+j+1;
				sum[i]+=cc[j];
				for(int e=1;e<=n;e++){
					c[e+t].u=n+j+1;
					c[e+t].v=e;
					c[e+t].w=d[j][e];
				}
				t+=n;
			}
		}
		sort(c+1,c+t+1,cmp);
		//for(int j=1;j<=t;j++)printf("%lld %lld %lld\n",c[j].u,c[j].v,c[j].w);
		for(int j=1;j<=t;j++){
			fdfa(c[j].u);
			fdfa(c[j].v);
			//printf("%lld-%lld-%lld\n",j,fa[c[j].u],fa[c[j].v]);
			if(fa[c[j].u]!=fa[c[j].v]){
				fa[fa[c[j].v]]=fa[c[j].u];
				sum[i]+=c[j].w;
			}
		}
		//printf("%lld\n",sum[i]);
		if(sum[i]<ans)ans=sum[i];
	}
	printf("%lld",ans);
	return 0;
}
