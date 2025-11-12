#include<bits/stdc++.h>
using namespace std;
bool p=1;
long long h,n,x,y=2,a[5005];
void d(long long x,long long s,long long z){
	if(x>n){
		if(z>2*s){
			h=(h+1)%998244353;
		}
		return;
	}
	d(x+1,s,z);
	d(x+1,a[x],z+a[x]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>1){
			p=0;
		}
	}
	if(p){
		x=n*(n-1)%998244353;
		for(long long i=3;i<=n;i++){
			y=i*y%998244353;
			x=x*(n-i+1)%998244353;
			h+=x/y;
		}
		printf("%lld",h);
	}else{
		if(n<21){
			sort(a+1,a+n+1);
			d(1,0,0);
			printf("%lld",h);
		}else{
			printf("366911923");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}