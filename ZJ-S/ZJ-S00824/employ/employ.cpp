#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,MOD=998244353;
int n,m;
char s[N];
int c[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s);
	for(int i=1;i<=n;i++)scanf("%lld",c+i);
	int res=1;
	for(int i=1;i<=n;i++){
		res=res*i%MOD;
	}printf("%lld",res);
	return 0;
}
