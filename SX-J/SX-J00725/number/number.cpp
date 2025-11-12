#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
string s;
ll a[N];
bool flas;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[s[i] - '0'] += 1;
	}
	for (int i = 9; i >= 0; i--) {
		if (a[i] > 0) {

			if (i > 0)
				flas = 1;
			if (flas == 1) {
				for (int j = 1; j <= a[i]; j++)
					cout << i;
			}
		}
	}
	if (flas == 0)
		cout << 0;
	return 0;
}