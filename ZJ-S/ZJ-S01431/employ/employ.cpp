#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=200005;
const int INF=0x3f3f3f3f;
char s[N];
int c[N],p[N];
ll fac[N],inv[N],jv[N];
void com_init(int n){
	inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=jv[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
		jv[i]=jv[i-1]*inv[i]%mod;
	}
}
ll com(int n,int m){
	if(n<m||m<0) return 0;
	return fac[n]*jv[m]%mod*jv[n-m]%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	int tot=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') s[i]='1';
		else s[i]='0';
		tot+=(s[i]=='0');
		p[i]=i;
	}
	int cc=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0) cc++;
	}
	if(cc==n){
		printf("0\n");
		return 0;
	}
	ll ans=0;
	do{
		int cnt=0,t=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1') cnt++;
			else{
				if(cnt>=c[p[i]]) cnt++;
				else t++;
			}
			if(t>=m){
				ans++;
				break;
			}
		}
	}while(next_permutation(p+1,p+n+1));
	printf("%lld\n",ans);
	return 0;
}
/*
4 1
1001
0 8 2 0
*/
