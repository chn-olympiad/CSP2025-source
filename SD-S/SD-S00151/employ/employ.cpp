#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+5;
const long long Mod=998244353;
int n,m,a[N];
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for (i=1;i<=n;i++) ans=(ans*i)%Mod;
	printf("%lld\n",ans);
	return 0;
}

