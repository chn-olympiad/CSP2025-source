#include <bits/stdc++.h>
using namespace std;
char a[100000];
int b[100000];

int mp(int c, int d) {
	if (c < d) {
		return d;
	}
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b[i] = int(s[i]) - 48;
			sum++;
		}
	}
	sort(b + 1, b + sum + 1, mp);
	for (int i = 0; i < sum; i++) {
		for (int j = 0; j < sum; j++) {
			if (b[j] < b[j + 1]) {
				swap(b[j], b[j + 1]);
			}
		}
	}
	for (int i = 0; i < sum ; i++) {
		cout << b[i];
	}
	return 0;
}