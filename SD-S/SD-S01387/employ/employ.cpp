#include<bits/stdc++.h>
using namespace std;
long long n,m,a[550],x,y,z;
long long const B=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=a[i-1]*i;
		a[i]%=B;
	}
	printf("%lld",(a[n]/(a[m]*a[n-m])%B)%B);
	return 0;
}
