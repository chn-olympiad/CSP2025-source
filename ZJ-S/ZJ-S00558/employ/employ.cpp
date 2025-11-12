#include <bits/stdc++.h>
using namespace std;
const int N=525,M=1e6+5,K=18,mod=998244353;
int n,m,c[N],p[N],ans;
char s[N];
int f[1<<K][K+2],fac[N];
int cnt(int x){
	int res=0;
	while(x)x-=x&-x,res++;
	return res;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*1ll*i%mod;
	for(int i=0;i<n;i++)p[i]=i;
	do
	{
		int fail=0,cnt=0;
		for(int i=0;i<n;i++){
			if(fail<c[p[i]]&&s[i]=='1')cnt++;
			else fail++;
		}
		ans+=(cnt>=m);
	}while(next_permutation(p,p+n));
	cout<<ans<<'\n';
//	ans=0;
//	f[0][0]=1;
//	for(int i=0;i<(1<<n);i++){
//		for(int j=0;j<n;j++){
//			if(i>>j&1)continue;
//			for(int k=n;~k;k--){
//				if(s[cnt(i)+1]=='0'||cnt(i)-k>=c[j]){
//					f[i|(1<<j)][k]=(f[i|(1<<j)][k]+f[i][k])%mod;
//				}else f[i|(1<<j)][k+1]=(f[i|(1<<j)][k+1]+f[i][k])%mod;
//			}
//		}
//	}
//	for(int i=m;i<=n;i++)ans=(ans+f[(1<<n)-1][i])%mod;
//	cout<<ans<<'\n';
}