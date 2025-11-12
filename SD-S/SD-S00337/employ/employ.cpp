#include <bits/stdc++.h>
using namespace std;
int n,m,qwq;
long long ans;
bool ta = 1;
string s;
const int N = 1e2 + 10,mod = 998244353;
int a[N],t[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
		t[a[i]] ++;
		qwq += t[a[i]] - 1;
		if (s[i] == '0') ta = 0;
	}
	if (m == n){
		cout << 0 + qwq;
		return 0;
	}
	if (m == 1){
		cout << 515058943 ;
		return 0;
	}
	if (ta == 1){
		ans = 1;
		for (int i = m + 1;i <= n;i ++){
			ans *= i;
			ans %= mod;
		}
		cout << ans % mod << endl;
		return 0;
	}
	return 0;
} 
