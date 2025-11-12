#if defined(DEBUG) && !defined(_GLIBCXX_DEBUG)
#define _GLIBCXX_DEBUG
#endif

#define IO_FILE_NAME "employ"
//#define LOCAL_FILE_IO

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define ldebug(...) fprintf(stderr, __VA_ARGS__)
void lassert(bool cond, string mess = "") {
    using namespace chrono;
    if (!cond) {
        cerr << "\nlassert fail: " << mess << "\n\n";
        this_thread::sleep_for(hours(1));
    }
}
#else
#define ldebug(...) (void)0
#define lassert(...) (void)0
#endif

using ui = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

template <typename T, typename U>
bool ckmax(T& a, const U& b) {
    return a < b && (a = b, true);
}
template <typename T, typename U>
bool ckmin(T& a, const U& b) {
    return b < a && (a = b, true);
}

constexpr ui MAXN = 505;
ui N, M;
u64 ans;
string s;
array<ui, MAXN> c;
constexpr u64 MOD = 998'244'353;
array<u64, MAXN> fac, ifac;

u64 qpow(u64 a, u64 b) {
    u64 r = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            r = r * a % MOD;
        }
        a = a * a % MOD;
    }
    return r;
}
u64 comb(ui n, ui m) {
    if (m > n) {
        return 0;
    }
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}
void test_case() {
    cin >> N >> M >> s;
    for (ui i = 0; i < N; ++i) {
        cin >> c[i];
    }
    // f[i][j]: i 中的人参加了面试，j 个人没入
    vector<vector<u64>> f(1 << N, vector<u64>(N + 1, 0));
    f[0][0] = 1;
    for (ui i = 0; i < (1U << N); ++i) {
        ui cnt = __builtin_popcount(i);
        for (ui j = 0; j < N; ++j) {
            f[i][j] %= MOD;
            if (f[i][j]) {
//                ldebug("f[%u][%u] = %llu\n", i, j, f[i][j]);
                for (ui k = 0; k < N; ++k) {
                    if (i >> k & 1) {
                        continue;
                    }
                    bool fail = (s[cnt] == '0' || c[k] <= j);
//                    ldebug("i=%u j=%u k=%u fail=%d || %d\n", i, j, k, s[cnt] == '0', c[k] <= j);
                    f[i | 1U << k][j + fail] += f[i][j];
                }
            }
        }
    }
    for (ui i = M; i <= N; ++i) {
        ans += f[(1U << N) - 1][N - i];
    }
    cout << ans % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#if !defined(LOCAL)
    freopen(IO_FILE_NAME ".in", "r", stdin);
    freopen(IO_FILE_NAME ".out", "w", stdout);
#elif defined(LOCAL_FILE_IO)
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    ui T = 1;
//    cin >> T;
    for (ui ca = 1; ca <= T; ++ca) {
        test_case();
    }
}
