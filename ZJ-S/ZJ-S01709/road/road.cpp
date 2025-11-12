#include"cstdio"
#include"algorithm"
#define ll long long
const int M=2000010,N=20010;
inline ll min(ll x,ll y){return x<y?x:y;}
int n,m,k,f[N],cnt;
struct P{
	int x,y;
	ll z;
	bool operator<(const P&w)const{
		return z<w.z;
	}
}e[M];
ll p[20],sum,ans;
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].z);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&p[i]);
		for(int j=1;j<=n;j++){
			m++;
			e[m].x=j;e[m].y=i+n;
			scanf("%lld",&e[m].z);
		}
	}ans=1E15;
	std::sort(e+1,e+m+1);
	for(int s=0,zs;s<(1<<k);s++){
		sum=cnt=zs=0;
		for(int i=0;i<k;i++)if(((1<<i)&s)!=0)zs++,sum+=p[i+1];
		for(int i=1;i<=n+k;i++)f[i]=i;
		for(int i=1;i<=m;i++){
			if(e[i].y>n)
				if(((1<<(e[i].y-n-1))&s)==0)
					continue;
			int fx=find(e[i].x),fy=find(e[i].y);
			if(fx!=fy){
				f[fx]=fy;
				sum+=e[i].z;
				cnt++;
			}
			if(cnt==n+zs-1)break;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
T2
15:20完成
*/
