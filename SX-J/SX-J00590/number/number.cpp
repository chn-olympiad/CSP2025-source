#include <bits/stdc++.h>
using namespace std;
string a;
string m[1500];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin >> a;
	int len = a.size();
	for (int i = 0; i < len; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			m[i] = a[i];
		}
	}
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= len; j++) {
			if (m[j] <= m[j + 1]) {
				swap(m[j], m[j + 1]);

			}
		}
	}
	return 0;
}