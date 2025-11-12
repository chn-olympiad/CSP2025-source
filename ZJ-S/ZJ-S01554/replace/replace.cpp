#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x = 0, y = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') y = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * y;
}
const int N = 1e5 + 7;
int n, q;
string s1[N], s2[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(); q = read();
	if (n > 10000) {
		for (int i = 1; i <= q; i++) puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	for (int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			int flag = t1.find(s1[j]);
			if (flag >= 0) {
//				printf("flag : %d\n" ,flag);
//				cout << s1[j] << " ";
				string t3 = t1.substr(0, flag) + s2[j] + t1.substr(flag + s2[j].length(), t1.length() - flag - s2[j].length());
//				cout << t3 << "\n";
				ans += (t3 == t2);
			}
		}
		printf("%d\n", ans);
			
	}
	return 0;
}
