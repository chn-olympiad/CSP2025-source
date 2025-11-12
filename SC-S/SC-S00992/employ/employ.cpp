#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long MAXN = 1000000;
long long n,m,data1[MAXN],sum;
char data2[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (long long i = 1;i <= n;i ++){
		scanf("%c",&data2[i]);
	}
	for (long long i = 1;i <= n;i ++){
		scanf("%lld",&data1[i]);
	}
	sum = 1;
	for (long long i = 1;i <= n;i ++){
		sum = ((sum % mod) * (i % mod)) % mod;
	}
	cout << sum % mod << endl;
	return 0;
}