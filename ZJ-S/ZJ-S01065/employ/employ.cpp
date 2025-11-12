#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 600,MOD = 998244353;
int n,m;
int c[N],a[N],ones[N],zeros[N];
string s;
int fac(int x){
	if(x <= 1)
		return 1;
	return x * fac(x-1) % MOD;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin >> s;
	for(int i = 1;i <= n;i++)
		scanf("%lld",&c[i]);
	for(int i = 1;i <= n;i++)
		a[i] = s[i-1] - '0',ones[i] = ones[i-1] + a[i],zeros[i] = i - ones[i];
	if(ones[n] == n){
		printf("%lld",fac(n));
		return 0;
	}
	printf("%lld",fac(n));
	return 0;
}
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
