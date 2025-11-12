#include <bits/stdc++.h>
using namespace std;
long long p=998244353;
int n;
long long jc(int n){
	long long res=1;
	for(int i=2;i<=n;i++) res=res*i%p;
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d",&n);
	printf("%lld",jc(n));
	return 0;
}