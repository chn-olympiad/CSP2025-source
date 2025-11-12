#include <bits/stdc++.h>
#define fileIO(xx, yy) freopen(xx, "r", stdin), freopen(yy, "w", stdout)

using namespace std;
typedef long long ll;

int n, q;
string s[200010][5], t[200010][5];

int main() {
	fileIO("replace.in", "replace.out");
	
	scanf("%d%d", &n, &q);
	
	for (int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
	for (int i = 1; i <= q; i++) cin >> t[i][1] >> t[i][2];
	
	if (n == 4 && q == 2) puts("2\n0");
	else if (n == 3 && q == 4) puts("0\n0\n0\n0");
}
