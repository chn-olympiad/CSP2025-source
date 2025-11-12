//[HRH]'s Code
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const long long Q=998244353;
long long n,m,T,op;
long long c[N];
long long a[15][50010];
int fa[N];
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
long long f[2020][2020];
struct ll{
	int x,y;
	long long w;
}q[N];
bool cmp(ll x,ll y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&T);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&q[i].x,&q[i].y,&q[i].w);
	}
	for(int i=1;i<=T;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(!T){
		sort(q+1,q+m+1,cmp);
		for(int i=1;i<=m;i++){
			int x=find(q[i].x),y=find(q[i].y);
			if(x==y)continue;
			fa[x]=y;op+=q[i].w;
		}printf("%lld",op);
		return 0;
	}
	else{
		memset(f,63,sizeof(f));
		for(int i=1;i<=m;i++){
			f[q[i].x][q[i].y]=f[q[i].y][q[i].x]=min(f[q[i].x][q[i].y],q[i].w);
		}
		for(int i=1;i<=T;i++){
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					f[j][k]=f[k][j]=min(f[j][k],a[i][j]+a[i][k]);
				}
			}
		}m=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				q[++m]=ll{i,j,f[i][j]};
			}
		}sort(q+1,q+m+1,cmp);
		for(int i=1;i<=m;i++){
			int x=find(q[i].x),y=find(q[i].y);
			if(x==y)continue;
			fa[x]=y;op+=q[i].w;
		}printf("%lld",op);
	}
	return 0;
}
/**/

