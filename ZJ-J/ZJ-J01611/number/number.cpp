#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
string s;
int n, cnt;
int a[N];
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	s = '#' + s;
	for(int i = 1; i <= n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++cnt] = (s[i] - '0');
		}
	}
	sort(a + 1, a + 1 + cnt);
	for(int i = cnt; i >= 1; i--)
		printf("%lld", a[i]);
	return 0;
}
