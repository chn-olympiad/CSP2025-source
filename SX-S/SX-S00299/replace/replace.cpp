#include <bits/stdc++.h>
using namespace std;

struct ss {
	string a, b;
	int length;
} s[200005];

int main() {
	freopen("replace1.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> s[i].a >> s[i].b, s[i].length = s[i].a.length();
	while (q--) {
		cin >> s[0].a >> s[0].b;
		int size = s[0].a.length(), sum = 0, ft;
		for (int i = 0; s[0].a[i] != s[0].b[i]; ++i)
			ft = i;
		++ft;
		for (int i = 1; i <= n; ++i) {
			string stra = s[0].a;
			int msize = size - s[i].length;
			for (int j = 0; j <= msize; ++j) {
				if (stra[j] == s[i].a[0]) {
					bool lean = 1;
					for (int k = 1; k <= s[i].length && lean; ++k)
						lean = stra[k + j] == s[i].a[k];
					if (!lean)
						continue;
					for (int k = 0; k <= s[i].length; ++k)
						stra[k + j] = s[i].b[k];
					if (stra == s[0].b)
						++sum;
				}
			}
		}
		cout
		        << sum << endl;
	}
	return 0;
}
