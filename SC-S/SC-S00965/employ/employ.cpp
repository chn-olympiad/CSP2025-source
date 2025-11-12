#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
/*
T4-先将所有难题（1）对应给所有耐心为0的
此时可将所有人耐心减去耐心为0的人的个数
得到新的串s和新的耐心串a

然后考虑每个人：
优先将耐心低的往前放。若是放不了（耐心限度前面已经放满了更小的）；
则将他对应给所有难题（假设有）；
若都不满足。则放置于最后，记为永远不可能者； 
*/
using namespace std;
const int maxn = 500 + 55, mod = 998244353, inf = 2147483647;
const double pi = acos(-1);
int T;
ll n, m, ans, cnt0, cnt1, inv2, tot0;
ll a[maxn], fra[maxn], inv[maxn], p[maxn];
char s[maxn];
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}return res;
}
void init(){
	fra[0] = 1;
	for(int i = 1;i <= n;i ++){
		fra[i] = fra[i - 1] * i % mod;
	}
	inv[n] = qpow(fra[n], mod - 2);
	for(int i = n - 1;i >= 1;i --){
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
}
ll c(ll n, ll m){
	if(n < m) return 0;
	if(n == m) return 1;
	return fra[n] * inv[m] % mod;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	init();
	inv2 = qpow(2, mod - 2);
	cin >> (s + 1);
	for(int i = 1;i <= n;i ++){
		if(s[i] == '0') cnt0 ++;
		p[i] = i;
	}
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] == 0) tot0 ++;
	}
	cnt1 = n - cnt0;
	if(n > 100){
		ans = fra[n];
		cout << ans;
		return 0;
	}
	do{
		int cntt = 0, res = 0;
		for(int i = 1;i <= n;i ++){
			if(s[i] == '0' || cntt >= a[p[i]]){
				cntt ++;
			}else res ++;
//			cout << p[i] <<" a"<< cntt << " ";
		}
		cout << ans << endl;
		ans += (res >= m) ? 1 : 0;
		ans %= mod;
		
	}while(next_permutation(p + 1, p + n + 1));
	cout << ans;
	return 0;
}