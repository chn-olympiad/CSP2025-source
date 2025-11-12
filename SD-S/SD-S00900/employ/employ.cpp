#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e2+10;
const int M=(1<<20);
const int MOD=998244353;
int n,m,c[N];
int f[M][20];
LL fac[N],inv[N];
char s[N];
bool o=true;
LL fun(LL x,LL y) {
	if(y==0) return 1;
	LL num=fun(x,y/2);
	if(y%2==0) return num*num%MOD;
	else return num*num%MOD*x%MOD;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,(s+1));
	for(int i=1; i<=n; i++) {
		if(s[i]!='1') o=false;
	}
	for(int i=1; i<=n; i++) scanf("%d",&c[i]);
	f[0][0]=1;
	fac[0]=1;
	for(int i=1; i<=n; i++) fac[i]=fac[i-1]*i%MOD;
	inv[n]=fun(fac[n],MOD-2);
	for(int i=n-1; i>=0; i--) inv[i]=inv[i+1]*(i+1)%MOD;
	if(n<=18) {
		int ma=(1<<n)-1;
		f[0][0]=1;
		for(int i=0; i<ma; i++) {
			for(int j=0; j<n; j++) {
				if(!f[i][j]) continue;
				int cnt=0;
				for(int k=0; k<n; k++) {
					if((i>>k)&1) cnt++;
				}
				for(int k=0; k<n; k++) {
					if((i>>k)&1) continue;
					int t=(i|(1<<k));
					if(s[cnt+1]=='0') {
						f[t][j]=(f[t][j]+f[i][j])%MOD;
					} else {
						if((cnt-j)>=c[k+1]) f[t][j]=(f[t][j]+f[i][j])%MOD;
						else f[t][j+1]=(f[t][j+1]+f[i][j])%MOD;
					}
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++) ans=(ans+f[ma][i])%MOD;
		cout<<ans;
	} else if(m==n){
		if(!o) cout<<0;
		else{
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					cout<<0;
					return 0;
				}
			}
			cout<<fac[n];
		}
	}
	return 0;
}

