#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n,m,c[18],f[1<<18][20];
char a[505];

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",a+1),a[0]='1';
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	f[0][0]=1;
	int S=(1<<n)-1;
	for(int i=0;i<S;i++) {
		for(int j=0;j<=n;j++) {
			for(int k=0;k<n;k++)if(!(i&1<<k)) {
				if(j>=c[k] || a[__builtin_popcount(i)+1]=='0') {
					(f[i|1<<k][j+1]+=f[i][j])%=mod;
				} else {
					(f[i|1<<k][j]+=f[i][j])%=mod;
				}
			}
		}
	}
	int ans = 0;
	for(int j=0;j<=n-m;j++) {
		(ans+=f[S][j])%=mod;
	} printf("%d",ans);
	
	return 0;
}
/*

*/
