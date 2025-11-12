#include <bits/stdc++.h>

const int maxn = 2e5;
int n, q;
int L[maxn + 5];
std::string s[2][maxn + 5], t[2][maxn + 5];
const unsigned long long b1 = 1331;
unsigned long long hs[2][maxn + 5];
unsigned long long hsh[2][5000005];

unsigned long long Pow(unsigned long long base, unsigned long long power) {
    unsigned long long res = 1;
    while (power) {
        if (power & 1) {
            res = res * base;
        }
        base = base * base;
        power >>= 1;
    }
    return res;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++ i) {
        std::cin >> s[0][i] >> s[1][i];
        if (s[0][i] == s[1][i]) {
            -- i;
            -- n;
            continue;
        }
        for (unsigned j = 0; j < s[0][i].size(); ++ j) {
            if (s[0][i][j] != s[1][i][j]) {
                L[i] = j;
                break;
            }
        }

        hs[0][i] = hs[1][i] = 0;
        for (unsigned j = 0; j < s[0][i].size(); ++ j) {
            hs[0][i] = hs[0][i] * b1 + (unsigned long long)s[0][i][j];
            hs[1][i] = hs[1][i] * b1 + (unsigned long long)s[1][i][j];
        }
    }

    for (int i = 1; i <= q; ++ i) {
        std::cin >> t[0][i] >> t[1][i];
        int l = 0;
        for (unsigned j = 0; j < t[0][i].size(); ++ j) {
            if (t[0][i][j] != t[1][i][j]) {
                l = j;
                break;
            }
        }

        hsh[0][0] = (unsigned long long)t[0][i][0];
        hsh[1][0] = (unsigned long long)t[1][i][0];
        for (unsigned j = 1; j < t[0][i].size(); ++ j) {
            hsh[0][j] = hsh[0][j - 1] * b1 + (unsigned long long)t[0][i][j];
            hsh[1][j] = hsh[1][j - 1] * b1 + (unsigned long long)t[1][i][j];
        }

        int ans = 0;
        for (int j = 1; j <= n; ++ j) {
            if (l >= L[j]) {
                if (hs[0][j] == hsh[0][l - L[j] + s[0][j].size() - 1] - (l - L[j] - 1 >= 0 ? hsh[0][l - L[j] - 1] * Pow(b1, s[0][j].size()) : 0)) {
                    if (hs[1][j] == hsh[1][l - L[j] + s[1][j].size() - 1] - (l - L[j] - 1 >= 0 ? hsh[1][l - L[j] - 1] * Pow(b1, s[1][j].size()): 0)) {
                        ++ ans;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }


    
    return 0;
}

