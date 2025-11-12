#include <bits/stdc++.h>
#define int long long
#define mod 998244353ll
#define N 300
using namespace std;
int pkg[N],ch[N],n,m;
int s[N],c[N],ans;
void check(){
	int tmp[N]{},sz[N]{};
	for (int i = 1;i <= n;i++) tmp[i] = ch[c[i]];
	int dig = 0;
	for (int i = 1;i <= n;i++){
		if (i == 1 && tmp[i] != 0){
			dig++;
			sz[i] = 1;
		}
		if (tmp[i] == 0) continue;
		int pic = 0;
		if (s[i] == 1){
			for (int j = i;j >= i - tmp[i];j--){
				if (sz[j] == 1) pic = 1;
			}
			if (pic == 1) dig++;
		}
	}
	if (dig == m) ans++;
}
void dfs(int now){
	if (now > n){
		check();
		return;
	}
	for (int i = 1;i <= n;i++){
		if (pkg[i] == 0){
			ch[now] = i;
			pkg[i] = 1;
			dfs(now + 1);
			pkg[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%lld",&s[i]);
	for (int i = 1;i <= n;i++) scanf("%lld",&c[i]);
	dfs(0);
	printf("%lld",ans);
return 0;
}
