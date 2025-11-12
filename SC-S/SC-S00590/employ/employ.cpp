#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5,mod=998244353;
int n,m;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int as=1;
	for(int i=n;i>=1;i--){
		as=as*i;
		as%=mod;
	}
	printf("%lld",as%mod);
	return 0;
}