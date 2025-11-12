#include<bits/stdc++.h>
using namespace std;
long long a[5001];
long long check(long long b,long long c){
	if(b==c) return c;
	else return b*(check(b-1,c));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,x=-1,ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		x=max(x,a[i]);
	}
	if(x==1){
		for(int i=3;i<=n;i++){
			ans=(ans+(check(n,n-i+1))/(check(i,1)))%998244353;
		}
		printf("%lld",ans);
	}
	else if(n==3){
		if((a[1]+a[2]+a[3])>(x*2)) printf("1");
		else printf("0");
	}
	return 0;
}
