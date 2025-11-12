#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int f[N];
string s[N];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 0;i < 128;i++) {
		f[i] = i;
	}
	int cnt = 0;
	int sum = 0;
	while (n--) {
		string s1,s2;
		cin >> s1 >> s2;
		s[1 + cnt] = s1;
		s[2 + cnt] = s2;
		cnt++;
	}
	if (q == 1) {
		string t1,t2;
		cin >> t1 >> t2;
		for (int i = 1;i <= 2 * n;i++) {
			if (t1 == s[i]) {
				if (t2 == s[i + 1]) {
					sum++;
				}
			}else {
				
			}
		}
	}
	cout << sum << endl;
	return 0;
}