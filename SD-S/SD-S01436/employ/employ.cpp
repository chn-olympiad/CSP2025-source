#include <bits/stdc++.h>
using namespace std;

const int N = 510,mod = 998244353;
typedef long long LL;
string s;
LL n,m,ans;
LL c[N];
bool r[N];
int a[N];
LL fun(LL x){
	LL res = 1;
	for(LL i = 1;i <= x;i++){
		res = res * i % mod;
	}
	return res % mod;
}
void check(){
	LL sum = 0;
	for(int i = 1;i <= n;i++) if(sum >= c[a[i]] || s[i - 1] == '0') sum++;
	if(n - sum >= m) ans++;
}
void dfs(int x){
	if(x == n + 1){
		check();
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!r[i]){
			r[i] = true;
			a[x] = i;
			dfs(x + 1);
			r[i] = false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i <= n;i++) cin>>c[i];
	bool f = true;
	for(int i = 0;i < n;i++){
		if(s[i] == '0'){
			f = false;
			break;
		}
	}
	if(f || m == 1){
		cout<<fun(n) % mod;
		return 0;
	}
	if(n <= 10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
}
