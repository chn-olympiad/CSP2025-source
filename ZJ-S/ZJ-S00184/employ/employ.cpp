#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 5;
int n, m, c[N], p[N];
string s;
ll ans;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		p[i] = i;
	}
	do {
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(i - 1 - cnt < c[p[i]] && s[i - 1] == '1') cnt++;
		}
		if(cnt >= m) {
			ans++;
		}
	} while(next_permutation(p + 1, p + n + 1));
	cout << ans;
	return 0;
}

