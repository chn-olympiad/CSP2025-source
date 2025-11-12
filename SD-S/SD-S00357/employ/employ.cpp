#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#define ll long long
#define endl '\n'
#define debug cout << "debug" << endl
using namespace std;

const int N = 505, mod = 998244353;
char s[N];
int n, m, a[N], cnt[N] = {0}, cnt2 = 0, c[N][N];
ll ans = 1;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i], cnt[i] = cnt[i - 1];
		if(s[i] == '1') cnt[i]++;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > 0) cnt2++;
	}
	for(int i = 1; i <= cnt2; i++)
		ans *= i, ans %= mod;
	cout << ans % mod;
	return 0;
}

