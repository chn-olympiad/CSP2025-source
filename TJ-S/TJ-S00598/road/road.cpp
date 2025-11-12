#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cassert>
const int N=20015,M=2000015;
int n,m,k,en;
int x[M],y[M];
struct edge{
	int x,y,z;
	friend bool operator < (const edge &a,const edge &b){
		return a.z<b.z;
	}
}e[M+N*15];
int c[N];
namespace Force{
	int fa[N];
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){ fa[find(x)]=find(y);}
	void solve(){
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int s=0;s<(1<<m);s++){
			for(int s1=1;s1<(1<<k);s1++){
				for(int i=1;i<=n+k;i++){
					fa[i]=i;
				}
				long long sum=0;
				for(int i=1;i<=k;i++) if(s1>>(i-1)&1) sum+=c[i];
				for(int i=1;i<=m;i++) if(s>>(i-1)&1) {sum+=e[i].z;if(find(e[i].x)!=find(e[i].y)) merge(e[i].x,e[i].y);}
				bool ok=true;
				for(int i=1;i<=n;i++) if(find(i)!=find(1)) ok=false;
				if(ok) ans=std::min(ans,sum);
			}
			
		}
		printf("!%lld\n",ans);
	}
}
namespace Better{
	int fa[N];
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){ fa[find(x)]=find(y);}
	bool av[N];
	void solve(){
		long long ans=0x3f3f3f3f3f3f3f3f;
		std::sort(e+1,e+en+1);
		for(int i=1;i<=n;i++){
			av[i]=true;
		}
		for(int s=0;s<(1<<k);s++){
			for(int i=1;i<=n+k;i++){
				fa[i]=i;
			}
			for(int i=n+1;i<=n+k;i++) av[i]=false;
			long long sum=0;
			int cntk=0;
			for(int i=1;i<=k;i++) if(s>>(i-1)&1) {
				//printf("%d ",i); 
				sum+=c[i],cntk++,av[n+i]=true;
			}
			int cnt=0;
			for(int i=1;i<=en&&cnt<cntk+n-1;i++){
				if(av[e[i].x]&&av[e[i].y]&&find(e[i].x)!=find(e[i].y)){
					//printf("%d %d\n",e[i].x,e[i].y);
					merge(e[i].x,e[i].y),sum+=e[i].z,cnt++;
				}
			}
			//printf("%lld\n",sum);
			ans=std::min(ans,sum);
		}
		printf("%lld\n",ans);
		
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	en=m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&e[++en].z);
			e[en].x=n+i,e[en].y=j;
		}
	}
	//Force::solve();
	Better::solve();

	return 0;
}
