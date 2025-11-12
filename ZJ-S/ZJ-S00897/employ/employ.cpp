#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=505;
const int P=998244353;
int n,m,ans=1,c[M];
char s[M];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)
		ans=(ans*i)%P;
	printf("%lld",ans);
	return 0;
}