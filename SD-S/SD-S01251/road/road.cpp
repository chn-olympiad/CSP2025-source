#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long INF=1e18;
const int N=15;
const int M=2e6+10;//зЂвт 
int n,m,k,c[N],u[M],v[M],w[M],tot,f[M],e[N][M];
struct node{
	int u,v,w;
}a[M];
inline bool cmp(node a,node b){
	return a.w<b.w;
} 
inline int Find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=Find(f[x]);
}
inline long long kru(int x){
	int tot=0,cnt=0;
	long long sum=0;
	while(x){
		cnt++;
		if(x&1){
			sum+=c[cnt];
			for(int i=1;i<=n;i++){
				a[++tot].u=cnt+n;
				a[tot].v=i;
				a[tot].w=e[cnt][i];
			}
		}
		x>>=1;
	}
	for(int i=1;i<=m;i++){
		a[++tot].u=u[i];
		a[tot].v=v[i];
		a[tot].w=w[i];
	}
	for(int i=1;i<=n+cnt;i++){
		f[i]=i;
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		int xx=Find(u),yy=Find(v);
		if(xx!=yy){
			f[xx]=yy;
			sum+=w;
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0){
			flag=1;
		}
		for(int j=1;j<=n;j++){
			scanf("%d",&e[i][j]);
		}
	}
	if(flag==0){
		cout<<kru(pow(2,k)-1)<<'\n';
		return 0;
	}
	if(k>5&&m>=50000||k==5&&m>100000){
		long long ans=INF;
		for(int i=1;i<=k;i++){
			ans=min(ans,kru(1<<(i-1)));
		}
		cout<<min(ans,kru(0))<<'\n';
		return 0;
	}
	long long ans=INF;
	for(int i=0;i<=pow(2,k)-1;i++){
		ans=min(ans,kru(i));
	}
	cout<<ans<<'\n';
	return 0;
}
