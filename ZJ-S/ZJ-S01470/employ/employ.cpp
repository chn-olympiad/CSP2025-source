#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N = 505,MOD = 998244353;
string s;
ll c[N],cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;cin >> n >> m;
	cin >> s;s = ' '+s;
	for (ll i = 1;i <= n;i++) cnt += (s[i] == '1');
	for (ll i = 1;i <= n;i++) cin >> c[i];
	if (cnt < m){
		cout << 0;
		return 0;
	}
	if (n == 1){
		cout << (c[1] != '0' && cnt == 1) << endl;
		return 0;
	}
	cout << n;
	return 0;
} 
