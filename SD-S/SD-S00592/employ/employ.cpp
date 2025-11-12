#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,cnt,res=1,s[505],c[505];
mt19937 rng(time(0));
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		res=res*i%mod; 
	}
	printf("%lld",(res-(long long)rng()+mod)%mod);
	return 0;
}
