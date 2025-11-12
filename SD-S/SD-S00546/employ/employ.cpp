#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
/*
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<unordered_map>
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define bug cout<<"-------\n";
#define debug(x) cout<<#x<<'='<<x<<'\n';
#define file(FILENAME) freopen(FILENAME ".in","r",stdin),freopen(FILENAME ".out","w",stdout);
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl '\n'

const ll N = 505;
const ll mod = 998244353;

ll n, m;
string s;
ll a[N];
bool f[N];
ll ans;

void dfs(ll deep, ll llast) {
	if(deep == n + 1) {
		if(llast <= 0)ans++, ans %= mod;
		return ;
	}
	ll refuse_people = deep - 1 - m + llast;
	// 1
	if(s[deep] == '1') {
		for(int i = n; i >= 1; i--) {
			if(refuse_people < a[i]) {
				if(!f[i]) {
					f[i] = 1;
					dfs(deep + 1, llast - 1);
					f[i] = 0;
				}
			} else break;
		}
	}
	// 0
	if(s[deep] == '0') {
		for(int i = 1; i <= n; i++) {
			if(!f[i]) {
				f[i] = 1;
				dfs(deep + 1, llast);
				f[i] = 0;
			}
		}
	} else {
		for(int i = 1; i <= n; i++) {
			if(refuse_people >= a[i]) {
				if(!f[i]) {
					f[i] = 1;
					dfs(deep + 1, llast);
					f[i] = 0;
				}
			} else break;
		}
	}
}
void solve1() {
	ll id = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') {
			id = i;
			break;
		}
	}
	if(id == 0) return ;
	ll cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(id - 1 >= a[i]) cnt++;
		else break;
	}
	ans = (n - cnt);
	for(int i = 1; i < n; i++) {
		ans *= (n - i);
		ans %= mod;
	}
}
void solve2() {
	for(int i = 1; i <= n; i++)
		if(s[i] == '0' || a[i] == 0)return ;
	ans = 1;
	for(int i = 1; i <= n; i++) {
		ans *= i;
		ans %= mod;
	}
}
void solve3() {
	ll cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == 0)cnt++;
		else break;
	}
	if(n - cnt >= m) {
		ans = 1;
		for(int i = 1; i <= n; i++) {
			ans *= i;
			ans %= mod;
		}
	}
}
int main() {
	file("employ")
	CLOSE
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	bool flag = 1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(s[i] == '0')flag = 0;
	}
	sort(a + 1, a + 1 + n);
	if(n <= 18) {
		dfs(1, m);
	} else if(m == 1) {
		solve1();
	} else if(m == n) {
		solve2();
	} else if(flag) {
		solve3();
	} else {
		dfs(1, m);
	}
	cout << ans;
	return 0;
}

