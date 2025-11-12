#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
char s[505];
ll c[505];
ll ans = 0;
const ll p = 998244353;
bool b[505];
ll a[505];
ll r[505];
ll f[10000005];
ll calc(ll w){
	ll g = 0;
	ll x = 1;
	for(ll i = 1;i <= n;i++){
		if(b[i]){
			g += x;
		}
		x *= 2;
	}
	g += x * w;
	return g;
}
ll dfs(ll u,ll w){
	ll id = calc(w);
	if(f[id] < 1e15){
		return f[id];
	}
	ll an = 0;
	if(u - 1 - w > (n-m)){
		f[id] = 0;
		return 0;
	}
	for(ll i = 1;i <= n;i++){
		if(!b[i]){
			//c[u] = i;
			b[i] = 1;
			ll ww = w;
			if(s[u] == '1' && (u-1-w < a[i])){
				ww++;
			}
			if(ww >= m){
			//	printf("ans+%lld\n",r[n-u]);
		/*		for(ll j = 1;j <= u;j++){
					printf("%lld ",c[j]);
				}
				printf("\n");*/
				an = (an + r[n - u]) % p;
			}
			else{
				an += dfs(u+1,ww);
				an %= p;
			}
			b[i] = 0;
		}
	}
	f[id] = an;
	return an;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	memset(f,1,sizeof(f));
	r[0] = 1;
	for(ll i = 1;i <= n;i++){
		r[i] = r[i-1] * i % p;
	}
	scanf("%s",s+1);
/*	bool flag = 1;
	for(ll i = 1;i <= n;i++){
		if(s[i] == '0'){
			flag = 0;
		}
	}
	if(flag){*/
/*		ans = 1;
		for(ll i = 1;i <= n;i++){
			ans *= i;
			ans %= p;
		}*/
/*		printf("%lld",r[n]);
		return 0;
	}*/
	for(ll i = 1;i <= n;i++){
		scanf("%lld",&a[i]);	
	}
	ans = dfs(1,0);
	printf("%lld",ans);
	return 0;
}
