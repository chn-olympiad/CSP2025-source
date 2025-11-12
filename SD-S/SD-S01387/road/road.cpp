#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,f[11000];
struct as{
	long long q,w,e;
}a[1100000];
bool maa(as q,as w){
	return q.e<w.e;
}
long long qw(long long d){
	if(f[d]==0){
		return d;
	}
	return f[d]=qw(f[d]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if(x<=k||y<=k){
			continue;
		}
		t++;
		a[t].q=x;
		a[t].w=y; 
		a[t].e=z;
	}
	for(long long i=1;i<=k;i++){
		long long o;
		scanf("%lld",&o);
		for(long long j=1;j<=n;j++){
			long long l;
			scanf("%lld",&l);
			t++;
			a[t].q=i;
			a[t].w=j; 
			a[t].e=l;
		}
	}
	long long x=0,y=0;
	sort(a+1,a+t+1,maa);
	for(long long i=1;i<=n;i++){
		long long l=qw(a[i].q),r=qw(a[i].w);
		if(l!=r){
			y++;
			f[l]=r;
			x+=a[i].e;
			if(y==n-1){
				break;
			}
		}
	}
	printf("%lld",x);
	return 0;
}
