#include <bits/stdc++.h>
#define pSS pair <string, string>
#define pii pair <int, int>
#define pII pair <pii, pii>
#define ll long long
using namespace std;

const int N = 200010;
const int mod1 = 1e9 + 9, base1 = 10007;
const int mod2 = 998244353, base2 = 1145;
int n, q, v1[26], v2[26], tot, len[N];
int sumB1[5000010], sumB2[5000010];
int sum1[5000010], sum2[5000010];
int pwB1[5000010], pwB2[5000010];
map <pii, int> umapL, umapR;
map <pII, int> brute;
string s[N][2], A, B;
vector <pII> vec[N];
map <pii, int> toid;

int rnd (int l, int r) {
	return (ll)rand () * rand () % (r - l + 1) + l;
}

pii ghash (string &s, int l, int r) {
	if (l > r) return {0, 0};
	int ans1 = 0;
	for (int i = l; i <= r; i++)
		ans1 = ((ll)ans1 * base1 + v1[s[i] - 'a']) % mod1;
	int ans2 = 0;
	for (int i = l; i <= r; i++)
		ans2 = ((ll)ans2 * base2 + v2[s[i] - 'a']) % mod2;
	return {ans1, ans2};
}

void init_hash (int len) {
	for (int i = 1; i <= len; i++)
		sum1[i] = ((ll)sum1[i - 1] * base1 + v1[A[i] - 'a']) % mod1;
	for (int i = 1; i <= len; i++)
		sum2[i] = ((ll)sum2[i - 1] * base2 + v2[A[i] - 'a']) % mod2;
}
void initB (int len) {
	for (int i = 1; i <= len; i++)
		sumB1[i] = ((ll)sumB1[i - 1] * base1 + v1[B[i] - 'a']) % mod1;
	for (int i = 1; i <= len; i++)
		sumB2[i] = ((ll)sumB2[i - 1] * base2 + v2[B[i] - 'a']) % mod2;
}

pii fhash (int l, int r) {
	int x = (l > r) ? 0 : ((sum1[r] - (ll)sum1[l - 1] * pwB1[r - l + 1]) % mod1 + mod1) % mod1;
	int y = (l > r) ? 0 : ((sum2[r] - (ll)sum2[l - 1] * pwB2[r - l + 1]) % mod2 + mod2) % mod2;
	return {x, y};
}
pii fhashB (int l, int r) {
	int x = (l > r) ? 0 : ((sumB1[r] - (ll)sumB1[l - 1] * pwB1[r - l + 1]) % mod1 + mod1) % mod1;
	int y = (l > r) ? 0 : ((sumB2[r] - (ll)sumB2[l - 1] * pwB2[r - l + 1]) % mod2 + mod2) % mod2;
	return {x, y};
}

pii calc (pii x, pii y) {
	return {(x.first - y.first + mod1) % mod1, (x.second - y.second + mod2) % mod2};
}

signed main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	// freopen ("replace4.in", "r", stdin);
	// freopen ("myC.txt", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	
	srand (time (0));
	for (int i = 0; i < 26; i++)
		v1[i] = rnd (0, mod1 - 1);
	for (int i = 0; i < 26; i++)
		v2[i] = rnd (0, mod2 - 1);
	pwB1[0] = 1;
	for (int i = 1; i <= 5000000; i++)
		pwB1[i] = (ll)pwB1[i - 1] * base1 % mod1;
	pwB2[0] = 1;
	for (int i = 1; i <= 5000000; i++)
		pwB2[i] = (ll)pwB2[i - 1] * base2 % mod2;
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		len[i] = s[i][0].size ();
		s[i][0] = ' ' + s[i][0];
		s[i][1] = ' ' + s[i][1];
		int L = 0, R = len[i] + 1;
		for (int j = 1; j <= len[i]; j++)
			if (s[i][0][j] != s[i][1][j]) {
				L = j; break;
			}
		for (int j = len[i]; j >= 1; j--)
			if (s[i][0][j] != s[i][1][j]) {
				R = j; break;
			}
		if (L == 0 || R == len[i] + 1) {
			i--, n--; continue;
		}
		brute[{ghash (s[i][0], 1, len[i]), ghash (s[i][1], 1, len[i])}]++;
		pii now = calc (ghash (s[i][1], L, R), ghash (s[i][0], L, R));
		if (!toid[now]) toid[now] = ++tot;
		vec[toid[now]].push_back ({ghash (s[i][0], 1, L - 1), ghash (s[i][0], R + 1, len[i])});
	}
	for (int i = 1; i <= q; i++) {
		cin >> A >> B;
		if (A.size () != B.size ()) { puts ("0"); continue; }
		int sz = A.size ();
		int L = 0, R = sz + 1;
		A = ' ' + A, B = ' ' + B;
		for (int j = 1; j <= sz; j++)
			if (A[j] != B[j]) {
				L = j; break;
			}
		for (int j = sz; j >= 1; j--)
			if (A[j] != B[j]) {
				R = j; break;
			}
		if (sz >= 20) {
			pii now = calc (ghash (B, L, R), ghash (A, L, R));
			if (!toid[now]) { puts ("0"); continue; } init_hash (sz);
			int ans = 0; umapL.clear (), umapR.clear ();
			for (int i = 1; i <= L; i++) umapL[fhash (i, L - 1)] = 1;
			for (int i = sz; i >= R; i--) umapR[fhash (R + 1, i)] = 1;
			for (auto x : vec[toid[now]]) ans += (umapL[x.first] && umapR[x.second]);
			printf("%d\n", ans);
		} else {
			int ans = 0; init_hash (sz), initB (sz);
			for (int i = 1; i <= L; i++) for (int j = R; j <= sz; j++) {
				ans += brute[{fhash (i, j), fhashB (i, j)}];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}