#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
#define mp make_pair
using namespace std;
const int maxn=1e4+500,maxm=1e6+500;
int n,m,k,f[maxn],ans,c[12],mx,sum;
P g[12][maxn];
struct node{
	int u,v,w;
	bool friend operator<(node q1,node q2){
		return q1.w<q2.w;
	}
}a[maxm];
int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k),mx=(1<<k)-1;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)scanf("%lld",&g[i][j].first),g[i][j].second=j;
		sort(g[i]+1,g[i]+1+n);
	}sort(a+1,a+1+m);
	for(int i=1,j=1,u,v,w;i<=m&&j<n;i++){
		u=a[i].u,v=a[i].v,w=a[i].w;
		if(get(u)==get(v))continue;
		f[get(u)]=get(v),ans+=w,a[j++]=a[i];
	}//printf("%lld\n",ans);
//	for(int i=1;i<n;i++,printf("\n"))printf("%lld %lld %lld",a[i].u,a[i].v,a[i].w);
//	printf("\n");
	for(int S=1,cnt,tot;S<=mx;S++){sum=0,cnt=n-1,tot=n-1;
		for(int i=1;i<=n+k;i++)f[i]=i;
		for(int i=1;i<=k;i++)
			if(S>>(i-1)&1){
				sum+=c[i],cnt++;
				for(int j=1;j<=n;j++)
					if(g[i][j].first<a[n-1].w)a[++tot]={g[i][j].second,i+n,g[i][j].first};
					else break;
			}sort(a+n,a+1+tot);
//		for(int i=n;i<=tot;i++,printf("\n"))printf("%lld %lld %lld",a[i].u,a[i].v,a[i].w);
//		printf("\n");
		for(int i=1,j=n;cnt&&sum<ans;){
			if(a[i].w<a[j].w||j>tot){
				if(get(a[i].u)==get(a[i].v)){i++;continue;}
				f[get(a[i].u)]=get(a[i].v),sum+=a[i].w,i++,cnt--;
			}else{
				if(get(a[j].u)==get(a[j].v)){j++;continue;}
				f[get(a[j].u)]=get(a[j].v),sum+=a[j].w,j++,cnt--;
			}
		}ans=min(ans,sum);
//		printf("%lld\n",sum);
	}printf("%lld",ans);
	return 0;
}




