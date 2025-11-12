#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,c[10],m0,fa[10010];
long long a[10][10000],sum,ans;
bool b,b0;
struct ed{
	int u,v;
	long long w;
}e[1000000],e0[1100000];
bool cmp(ed e1,ed e2){
	return e1.w<e2.w;
}int findf(int x){
	if(fa[x]!=x)fa[x]=findf(fa[x]);
	return fa[x];
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),b=1;
	for(int i=0;i<m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}for(int i=0;i<k;i++){
		scanf("%d",&c[i]),b&=(!c[i]),b0=0;
		for(int j=0;j<n;j++){
			scanf("%lld",&a[i][j]),b0|=(!a[i][j]);
		}b&=b0;
	}if(k<=5){
		ans=1e15;
		for(int i=0;i<(1<<k);i++){
			m0=m,sum=0;
			for(int j=0;j<m;j++)e0[j]=e[j];
			for(int j=0;j<n;j++)fa[j]=j;
			for(int j=0;j<k;j++){
				if((i>>j)&1){
					for(int l=0;l<n;l++){
						e0[m0]={j+n+1,l+1,a[j][l]},m0++;
					}fa[j+n]=j+n,sum+=c[j];
				}
			}sort(e0,e0+m0,cmp);
			for(int j=0;j<m0;j++){
				if(findf(e0[j].u-1)!=findf(e0[j].v-1)){
					fa[findf(e0[j].u-1)]=findf(e0[j].v-1);
					sum+=e0[j].w;
				}
			}ans=min(ans,sum);
		}printf("%lld",ans);
		return 0;
	}if(b){
		for(int i=0;i<n;i++)fa[i]=i;
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				e[m]={i+n+1,j+1,a[i][j]},m++;
			}fa[i+n]=i+n;
		}sort(e,e+m,cmp);
		for(int i=0;i<m;i++){
			if(findf(e[i].u-1)!=findf(e[i].v-1)){
				fa[findf(e[i].u-1)]=findf(e[i].v-1);
				ans+=e[i].w;
			}
		}printf("%lld",ans);
		return 0;
	}ans=1e15;
	for(int i=0;i<k;i++){
		m0=m,sum=0;
		for(int j=0;j<m;j++)e0[j]=e[j];
		for(int j=0;j<n;j++){
			fa[j]=j,e0[m0]={i+n+1,j+1,a[i][j]},m0++;
		}sort(e0,e0+m0,cmp);
		for(int j=0;j<m0;j++){
			if(findf(e0[j].u-1)!=findf(e0[j].v-1)){
				fa[findf(e0[j].u-1)]=findf(e0[j].v-1);
				sum+=e0[j].w;
			}
		}if(sum<ans){
			ans=sum,m=m0;
			for(int j=0;j<m;j++)e[j]=e0[j];
		}
	}printf("%lld",ans);
	return 0;
}
