#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
char ch[N];
int a[N], t, s = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> (ch + 1);
	sort(ch + 1, ch + 1 + N, greater() );
	for (int i = 1; i <= N; i++) {
		for (char j = '0'; j <= '9'; j++) {
			if (ch[i] == j) {
				cout << j;
			}
		}
	}
	return 0;
}
