#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
long long sum[1000005];
long long cnt;

bool cmp(long long a, long long b) {
	return a > b;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			sum[i] = s[i] - '0';
		if (s[i] == '0')
			cnt++;
//		cout << s[i] << " ";
	}
	sort(sum, sum + len, cmp);
	for (int i = 0; i < len; i++) {
		if (sum[i] != 0)
			cout << sum[i];
	}
	for (int i = 1; i <= cnt; i++)
		cout << 0;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
