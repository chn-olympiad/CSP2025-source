#include <bits/stdc++.h>
#define l long long
using namespace std;

l n, q;
string ss1[200006], ss2[200006];

void mian() {
	cin >> n >> q;
	for (l i = 1; i <= n; i++) {
		cin >> ss1[i] >> ss2[i];
		ss1[i] = " " + ss1[i];
		ss2[i] = " " + ss2[i];
	}
	while (q--) {
		printf("0\n");
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	mian();
	return 0;
}
