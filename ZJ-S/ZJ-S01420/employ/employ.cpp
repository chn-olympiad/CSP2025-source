#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 505;
int read(){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){
		if (s == '-') f=-1;
		s=getchar();
	}while(isdigit(s)){
		x=x*10+s-'0';
		s=getchar();
	}return x*f;
}
int s[N],c[N];
ll fac[N],ifac[N];
ll qp(ll a,ll b){
	ll ans = 1;
	while(b){
		if (b&1) ans = ans*a%mod;
		b>>=1ll;
		a=a*a%mod;
	}return ans;
}
bool vis[N];
int n,m;
ll dfs(int pos,int sum,int fail) {
	if (pos == n+1) {
		if (sum>=m) return 1;
		return 0;
	}
//	if (sum>=m) {//puts("--");
//		return fac[n-pos+1];
//	}
	ll res = 0;
	for(int i=1;i<=n;i++) {
		if (!vis[i]) {
			vis[i] = 1;
			if (s[pos] == 1 && c[i]>fail) res = (res+dfs(pos+1,sum+1,fail))%mod;
			else res = (res+dfs(pos+1,sum,fail+1))%mod;
			vis[i]=0;
		}
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	n=read(),m=read();
	string s1;
	cin>>s1;
	for(int i=0;i<n;i++) s[i+1] = s1[i]-'0';
	fac[0] = 1;
	for(int i=1;i<=n;i++){
		c[i]=read();
		fac[i] = fac[i-1]*i%mod;
	}
	ifac[n] = qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--){
		ifac[i] = 1ll*ifac[i+1]*(i+1)%mod;
	}
	//printf("%lld\n",fac[3]*ifac[3]%mod);
	printf("%lld\n",dfs(1,0,0));
	return 0;
}/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
