#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int num[10000], c[10000];
	string s;
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; i ++) cin >> c[i], num[i] = i;
	int s1 = 0;
	do {
		int ans = 0, cnt = 0;
		for(int i = 1; i <= n; i ++) {
			if(cnt >= c[num[i]]) {cnt ++;continue;}
			if(s[i] == '0') cnt ++;
			else ans ++;
		}
		if(ans >= m) {
			s1 ++;
			s1 %= M;
		}
	}while(next_permutation(num + 1, num + 1 + n));
	cout << s1 << endl;
	return 0;
}


