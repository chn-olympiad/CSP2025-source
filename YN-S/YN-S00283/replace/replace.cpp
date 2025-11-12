#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long a, b;
	cin >> a >> b;
	for (long long i = 1; i <= a; i++) {
		string s, ss;
		cin >> s >> ss;
	}
	for (long long  i = 1; i <= b; i++) {
		string sss, ssss;
		cin >> sss >> ssss;
		long long  ans = 0;
		long long  len = sss.size();
		for (long long  j = 0; j < len; j++) {
			if (sss[j] == ssss[j])
				ans++;
		}
		if (ans == 0) {
			cout << 0 << endl;
		} else {
			cout << (len - ans)  << endl;
		}
	}

	return 0;
}
