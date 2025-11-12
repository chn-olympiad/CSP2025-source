#include<bits/stdc++.h>
using namespace std;
bool p;
long long k,m,n,s,c[15],z[10002],a[15][10002];
struct b{
	long long u,v,w;
}r[1000005];
bool C(b x,b y){
	return x.w<y.w;
}
long long f(long long x){
	if(z[x]==x){
		return x;
	}
	return z[x]=f(z[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&r[i].u,&r[i].v,&r[i].w);
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]){
			p=1;
		}
		for(long long j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]){
				p=1;
			}
		}
	}
	if(p){
		sort(r+1,r+m+1,C);
		for(long long i=1;i<=n;i++){
			z[i]=i;
		}
		for(long long i=1;i<=m;i++){
			if(f(r[i].u)!=f(r[i].v)){
				s+=r[i].w;
				z[f(r[i].u)]=f(r[i].v);
			}
		}
		printf("%lld",s);
	}else{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
