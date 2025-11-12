#include <bits/stdc++.h>
using namespace std;
string n;
long long o = 1;
char shu[114514];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] >= '0' && n[i] <= '9') {
			shu[o] = n[i];
			o++;
		}
	}
	sort(shu + 1, shu + o + 1);
	for (int i = o; i >= 1; i--) {
		cout << shu[i];
	}
	return 0;
}
