#include<bits/stdc++.h>
using namespace std;
const int MAXN=502,mod=998244353;
int n,m;
long long a[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	a[0]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) a[i]=a[i-1]*i%mod;
	printf("%lld",a[n]);
}