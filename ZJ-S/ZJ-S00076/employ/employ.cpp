#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	int s = 1;
	for(int i = 1; i <= m; i++){
		s = s * i % mod;
	}
	printf("%lld",s);
	return 0;
}