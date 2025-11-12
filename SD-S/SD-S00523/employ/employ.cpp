#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int MOD=998244353;
int fac[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	fac[0]=1; 
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i,fac[i]%=MOD;
	cout<<fac[n];
	return 0;
}
