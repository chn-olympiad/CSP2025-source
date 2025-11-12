#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
struct edge{
	int u,v,w;
}a[M],ve[M],pb[M];
int n,m,k,f[N],b[15][N],c[15],d[15];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int sf(int x){
	return f[x]=f[x]==x?x:sf(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	ll xd=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		xd+=c[i];
		for(int j=1;j<=n;j++)
		scanf("%d",&b[i][j]);
		if(c[i]==0){
			for(int j=1;j<=n;j++){
				if(b[i][j]==0){
					for(int k=1;k<=n;k++){
						if(k==j)continue;
						edge g;
						g.u=j,g.v=k,g.w=b[i][k];
						a[++m]=g;
					}
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(a+1,a+m+1,cmp);
	int cnt=0,id=0;
	ll ans=0;
	while(id<n-1){
		int u=a[++cnt].u,v=a[cnt].v,w=a[cnt].w;
		if(sf(u)!=sf(v)){
			ve[++id]=a[cnt];
			ans+=w;
			f[sf(u)]=sf(v);
		}
	}
	if(xd==0){
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			edge g;
			g.u=j,g.v=i+n,g.w=b[i][j];
			ve[++id]=g;
		}
	}
	sort(ve+1,ve+id+1,cmp);
	for(int t=1;t<(1<<k);t++){
		id=n-1;
		ll sum=0,K=0;
		for(int i=1;i<=k;i++)
		{
			if(t&(1<<(i-1))){
				sum+=c[i];
				K++;
				d[i]=t;
			}
		}
		for(int i=1;i<=n+k;i++)f[i]=i;
		int bh=0,cnt=0;
		while(bh<n+K-1){
			int u=ve[++cnt].u,v=ve[cnt].v,w=ve[cnt].w;
			if(v>n&&d[v-n]!=t)continue;
			if(sf(u)!=sf(v)){
				bh++;
				sum+=w;
				f[sf(u)]=sf(v);
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
}
