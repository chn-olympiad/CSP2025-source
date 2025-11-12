#include<bits/stdc++.h>
using namespace std;
long long n,m,fir,pm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&fir);
	for(long long i=2;i<=n*m;i++){
		long long x;
		scanf("%lld",&x);
		if(x>fir)pm++;
	}
	long long c=(pm+n-1)/n;
	printf("%lld ",c);
	if(c%2==1){
		long long r=pm%n;
		if(r==0)r=n;
		printf("%lld",r);
	}else{
		long long r=pm%n;
		if(r==0)r=n;
		r=n-r+1;
		printf("%lld",r);
	}
	return 0;
}
