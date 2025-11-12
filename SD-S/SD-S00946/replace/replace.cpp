#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
namespace {
using namespace std;
using u64 = uint64_t;
const int N = 5e6 + 5;
const u64 B = 233;
int n, q;
u64 b[N], h[N];
char s1[N], s2[N];
unordered_map<u64, int> M;
u64 sub(int l, int r) { return h[r] - h[l - 1] * b[r - l + 1]; }
namespace q1 {
const int M = 2e5 + 5;
int len[M];
vector<u64> h[M];
u64 sub(int id, int l, int r) { return h[id][r] - h[id][l - 1] * b[r - l + 1]; }
void solve() {
	for (int i = 1; i <= n; i++) {
		cin >> (s1 + 1) >> (s2 + 1);
		len[i] = strlen(s1 + 1);
		h[i].resize(len[i] + 1);
		for (int j = 1; j <= len[i]; j++) h[i][j] = (h[i][j - 1] * B + s1[j]) * B + s2[j];
	}
	cin >> (s1 + 1) >> (s2 + 1);
	len[0] = strlen(s1 + 1);
	h[0].resize(len[0] + 1);
	for (int j = 1; j <= len[0]; j++) h[0][j] = (h[0][j - 1] * B + s1[j]) * B + s2[j];
	int l = 1, r = len[0];
	while (s1[l] == s2[l]) ++l;
	while (s1[r] == s2[r]) --r;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1, k = r - l + 1; k <= len[i]; j++, k++)
			if (1 <= l - j + 1 && r - k + len[i] <= len[0] && sub(0, l - j + 1, r - k + len[i]) == sub(i, 1, len[i])) ++ans;
	cout << ans; 
}
} // namespace q1
} // namespace
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q, b[0] = 1;
	for (int i = 1; i <= 5e6; i++) b[i] = b[i - 1] * B * B;
	if (q == 1) return q1::solve(), 0;
	for (int i = 1; i <= n; i++) {
		cin >> (s1 + 1) >> (s2 + 1);
		int len = strlen(s1 + 1);
		u64 h = 0;
		for (int j = 1; j <= len; j++) h = (h * B + s1[j]) * B + s2[j];
		++M[h];
	}
	for (int i = 1; i <= q; i++) {
		cin >> (s1 + 1) >> (s2 + 1);
		int len = strlen(s1 + 1);
		for (int j = 1; j <= len; j++) h[j] = (h[j - 1] * B + s1[j]) * B + s2[j];
		int l = 1, r = len;
		while (s1[l] == s2[l]) ++l;
		while (s1[r] == s2[r]) --r;
		int ans = 0;
		for (int j = 1; j <= l; j++)
			for (int k = r; k <= len; k++) ans += M[sub(j, k)];
		cout << ans << '\n';
	}
}
