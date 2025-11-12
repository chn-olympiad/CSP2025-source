#include <iostream>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
inline LL read() {
    LL num = 0, sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1), ch = getchar();
    while ('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch - '0', ch = getchar();
    return (sign == 1 ? num : -num);
}
const int MAXN = 2e5 + 8;
const int MAXL = 1e6 + 8;
const ULL BASE = 31;
int n, q, len[MAXN];
ULL hs[MAXN], ht[MAXN], hqs[MAXL], hqt[MAXL];
ULL qpow(ULL base, ULL expo) {
    ULL ret = 1;
    for (;expo; base = base * base, expo >>= 1)
        if (expo & 1) ret = ret * base;
    return ret;
}
ULL get_hash(ULL h[], int l, int r) { return h[r] - h[l - 1] * qpow(BASE, r - l + 1); }
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    n = read(), q = read();
    bool tpB = true;
    for (int i = 1; i <= n; i++) {
        string s, t;
        cin >> s >> t;
        len[i] = s.length();
        ULL h = 0, cnt = 0;
        for (int j = 1; j <= len[i]; j++) {
            h = h * BASE + s[j - 1] - 'a' + 1;
            if (s[j - 1] == 'a') continue;
            else if (s[j - 1] == 'b') cnt++;
            else tpB = false;
        }
        hs[i] = h, tpB &= (cnt == 1);
        h = 0, cnt = 0;
        for (int j = 1; j <= len[i]; j++) {
            h = h * BASE + t[j - 1] - 'a' + 1;
            if (t[j - 1] == 'a') continue;
            else if (t[j - 1] == 'b') cnt++;
            else tpB = false;
        }
        ht[i] = h, tpB &= (cnt == 1);
    }
    while (q--) {
        string qs, qt;
        cin >> qs >> qt;
        int ans = 0, qlen = qs.length();
        if (qlen != qt.length()) {
            cout << "0\n";
            continue;
        }
        for (int i = 1; i <= qlen; i++) {
            hqs[i] = hqs[i - 1] * BASE + qs[i - 1] - 'a' + 1;
            hqt[i] = hqt[i - 1] * BASE + qt[i - 1] - 'a' + 1;
        }
        for (int i = 1; i <= n; i++)
            for (int l = 1; l + len[i] - 1 <= qlen; l++) {
                if (get_hash(hqs, l, l + len[i] - 1) != hs[i]
                 || get_hash(hqt, l, l + len[i] - 1) != ht[i]) continue;
                ans += get_hash(hqs, l + len[i], qlen) == get_hash(hqt, l + len[i], qlen);
                if (hqs[l] != hqt[l]) break;
            }
        cout << ans << "\n";
    }
    return 0;
}
