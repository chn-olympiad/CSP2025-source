#include<bits/stdc++.h>
using namespace std;
long long n,m,r,a,s[105],e;
bool cmp(long long x,long long y){
	return x>y;
}
int main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&e);
		s[i]=e;
		if(i==1) r=e;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==r){
			if(i%n!=0) a=i/n+1;
			else a=i/n;
			if(a%2==1){
				long long b=(i-1)%m+1;
				printf("%lld %lld",a,b);
				return 0;
			}
			long long b=n-(i-1)%m;
			printf("%lld %lld",a,b);
			return 0;
		}
	}
	return 0;
}
