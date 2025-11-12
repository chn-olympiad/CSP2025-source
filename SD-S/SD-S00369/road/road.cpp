#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long read(){
	long long x=0;
	char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') {
		x*=10;
		x+=(c-'0'); 
		c=getchar();
	}
	return x;
}
const int N=10005;
const int M=2000005;
int F[N];
struct edge{
	int x,y;
	long long z;
}e[M];
bool cmp(edge a,edge b){
	return a.z<b.z;
} 
void init(int n){
	for (int i=1;i<=n;i++){
		F[i]=i;
	}
} 
int Find(int x){
	if (x==F[x]) return x;
	return F[x]=Find(F[x]);
}
void link(int x,int y){
	int xx=Find(x);
	int yy=Find(y);
	F[xx]=yy;
}
bool Same(int x,int y){
	return (Find(x)==Find(y));
}
int n,m,k;
long long c[12][N];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	init(n);
	for (int i=1;i<=m;i++){
		e[i].x=read();
		e[i].y=read();
		e[i].z=read();
	}
	for (int i=1;i<=k;i++){
		c[i][0]=read();
		for (int j=1;j<=n;j++){
			c[i][j]=read();
		}
	}
	int cnt=m;
	if (k){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==j) continue;
				cnt++; 
				e[cnt].x=i;
				e[cnt].y=j;
				e[cnt].z=c[1][i]+c[1][j]; 
				for (int l=2;l<=k;l++){
					e[cnt].z=min(c[l][i]+c[l][j],e[cnt].z);
				}
			}
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int cntt=0;
	for (int i=1;i<=cnt;i++){
		if (cntt==n-1) break;
		int x=e[i].x,y=e[i].y,z=e[i].z;
		if (!Same(x,y)){
			link(x,y);
			ans+=e[i].z;
			cntt++;
		}
	}
	printf("%lld",ans);
    return 0;
}

