#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
const int maxn = 2e5 + 5;
//ull Base = 13331, Bases[maxn], valS[maxn];
string s[maxn][3], t[maxn][3];
int n, q;
bool check(string s2, string t1, string t2, int x) {
	int lenS = s2.length();
	for (int i = x; i < x + lenS; ++i) t1[i] = s2[i - x];
	return t1 == t2;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i][1] >> s[i][2];
//		for (int j = 0, lenS = s[i][1].length(); j < lenS; ++j)
//			valS[j] = valS[j] * Base + s[i][1][j] - 'a' + 1;
	}
	ll reply;
	for (int i = 1, lenT; i <= q; ++i) {
		cin >> t[i][1] >> t[i][2];
		lenT = t[i][1].length(), reply = 0;
		for (int j = 1, lenS; j <= n; ++j) {
			lenS = s[j][1].length();
			if (lenS > lenT) continue;
//			ll x = 0, y = 0;
//			for (int k = 0; k < lenS; ++k) {
//				y = y * Base + t[i][1][k] - 'a' + 1;
//			}
//			for (int k = lenS - 1; k < lenT; ++k) {
//				if (y - x * lenS == valS[j]) reply += check(s[j][2], t[j][1], t[j][2], k - lenS + 1);
//				y = y * Base + t[i][1][k] - 'a' + 1;
//				x = x * Base + t[i][1][k - lenS + 1] - 'a' + 1;
//			}
			for (int k = 0; k < lenT; ++k)
				if (t[i][1].substr(k, lenS) == s[j][1]) 
					reply += check(s[j][2], t[i][1], t[i][2], k);
		}
		cout << reply << endl;
	}
	return 0;
}