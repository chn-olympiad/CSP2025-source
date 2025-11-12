#include <bits/stdc++.h>
using namespace std;
string a[200005];
string b[200005];
int ba[200005];
int bb[200005];
long long M = 1e10;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	long long sum = n * q;
	if (sum >= M) {
		for (int i = 0; i < n; i++) {
			int fa = a[i].find("b");
			int fb = b[i].find("b");
			ba[i] = fa;
			bb[i] = fb;
		}
		while (q--) {
			int sum = 0;
			string q1, q2;
			cin >> q1 >> q2;
			int faq = q1.find("b");
			int fbq = q2.find("b");
			for (int i = 0; i < n; i++) {
				if (ba[i] == faq && bb[i] == fbq) {
					sum++;
				}
			}
			cout << sum << endl;
		}
	} else {
		while (q--) {
			int sum = 0;
			string q1, q2;
			cin >> q1 >> q2;
			string t = q1;
			for (int i = 0; i < n; i++) {
				if (t.find(a[i]) != string::npos) {
					t.replace(t.find(a[i]), (int)a[i].size(), b[i]);
					if (t == q2) {
						sum++;
					}
				}
				t = q1;
			}
			cout << sum << endl;
		}
	}

	return 0;
}