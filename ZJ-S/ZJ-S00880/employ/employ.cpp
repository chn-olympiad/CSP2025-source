#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500 + 2;
const int mod = 998244353;

int n, m;
int c[N], frac[N];
string s;

namespace sub1{
	
void init(){
	frac[0] = 1;
	for(int i = 1; i <= n; i ++)  frac[i] = frac[i - 1] * i % mod;
}
	
int solve(){
	s = '#' + s;
	sort(c + 1, c + n + 1);
	init();
	int j = 1, ans = 0;
	for(int i = 1; i <= n; i ++){
		if(s[i] = 1){
			while(c[j] < i)  j ++;
			if(j <= i){
				ans = (ans + frac[n - j + 1]) % mod;
				break;
			}
			ans = (ans + frac[n - j + 1]) % mod;
		}
	}
	cout << ans;
	
	return 0;
}

}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i ++)  cin >> c[i];
	if(m == 1)  return sub1::solve();

	return 0;
}
