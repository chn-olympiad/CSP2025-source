#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N=2e4+5,M=2e6+5;
struct stu{
	long long x,y,z;
}a[M];
long long n,m,k,f[N],ans,c[13],d[12][N],CNT=0;
bool cmp(stu A,stu B){
	return A.z<B.z;
}
int Find(long long u){
	if(f[u]==u){
		return u;
	}
	return f[u]=Find(f[u]);
}
void kru(){
	for(int i=1;i<=CNT;i++){
		long long U=Find(a[i].x),V=Find(a[i].y),w=a[i].z;
		if(U!=V){
			f[U]=V;
			ans+=w;
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	bool FLAG=0;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
	}
	CNT=m;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&d[i][j]);
		}
		if(c[i]!=0){
			FLAG=1;
		}
	}
	for(int i=1;i<=n+k;i++){
			f[i]=i;
	}
	if(k==0){	
		sort(a+1,a+1+m,cmp);
		kru();
		printf("%lld",ans);
		return 0;
	}
	if(!FLAG){
		for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			a[++CNT].x=i;
			a[CNT].y=j;
			a[CNT].z=d[i][j];
		}
	}
	sort(a+1,a+1+CNT,cmp);
	kru();
	printf("%lld",ans);
	return 0;
	}
	return 0;
}

