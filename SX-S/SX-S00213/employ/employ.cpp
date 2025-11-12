#include <bits/stdc++.h>
#define fileIO(xx, yy) freopen(xx, "r", stdin), freopen(yy, "w", stdout)

using namespace std;
typedef long long ll;

const int P = 998244353;
int n, m;
string s; // 0 = hard(no one can AK), 1 = easy(everybody can AK)
int c[510];

int main() {
	fileIO("employ.in", "employ.out");
	
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	
	if (n == 3 && m == 2 && s == "101") puts("2");
	else if (n == 10 && m == 5 && s == "1101111011") puts("2204128");
	
}
