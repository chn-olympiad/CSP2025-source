#include <bits/stdc++.h>
using namespace std; bool _bg;
struct mod {
    static constexpr unsigned M = 998244353;
    unsigned x;
    inline mod() : x() { }
    inline mod(const mod &) = default;
    inline mod(mod &&) = default;
    inline mod(int x) : x((x % M + M) % M) { }
    inline mod(unsigned x) : x(x % M) { }
    inline mod(unsigned x, bool) : x(x) { }
    inline mod& operator = (const mod &) = default;
    inline mod& operator = (mod &&) = default;
    friend mod operator + (mod a, mod b){
        unsigned x = a.x + b.x;
        return mod(x >= M? x - M : x, true);
    }
    friend mod operator - (mod a, mod b){
        unsigned x = a.x - b.x;
        return mod(x >> 31? x + M : x, true);
    }
    friend mod operator * (mod a, mod b){
        unsigned x = 1ull * a.x * b.x % M;
        return mod(x, true);
    }
    friend mod operator * (mod a, int b){
        return a * mod(b);
    }
    mod &operator += (mod b){
        return *this = *this + b;
    }
    mod &operator *= (mod b){
        return *this = *this * b;
    }
    friend ostream &operator << (ostream &os, mod a){
        return os << a.x;
    }
    operator bool() const {
        return x;
    }
};
int n, m;
string s;
int c[510], cc[510];
namespace S1 {//psd
    void sol1(){
        int p[20];
        iota(p + 1, p + n + 1, 1);
        int rs = 0;
        do {
            int s = 0;
            for (int i = 1; i <= n; ++i){
                bool us = ::s[i] - '0' && s + c[p[i]] >= i;
                s += us;
            }
            rs += s >= m;
        } while (next_permutation(p + 1, p + n + 1));
        cout << rs << endl;
        exit(0);
    }
}
// mod f[110][110][110];//f_{i,j,k} : v_{1~i}, sum=j, count (unused c <= i-j) = k
bool _ed; int main(){
    double mmusd_M = fabs(&_ed - &_bg) / 1024 / 1024;
    clog << "mem used:" << mmusd_M << "M" << endl; assert(mmusd_M < 256);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s; s = " " + s;
    for (int i = 1; i <= n; ++i)cin >> c[i], ++cc[c[i]];
    if (n <= 10)S1::sol1();//8pts
    // f[0][0][cc[0]] = 1;
    // for (int i = 0; i < n; ++i){
    //     bool ms = s[i + 1] - '0';
    //     for (int j = 0; j <= i; ++j)
    //         for (int k = 0; k <= n; ++k)if (mod u = f[i][j][k]){
    //             if (k)f[i + 1][j][k + cc[i + 1 - j] - 1] += f[i][j][k] * k;
    //             if (ms)f[i + 1][j + 1][k] += f[i][j][k] * (n - i - k);
    //             else {
    //                 if (cc[i + 1 - j]) f[i + 1][j][k + cc[i + 1 - j] - 1] += f[i][j][k] * cc[i + 1 - j];
    //                 f[i + 1][j][k + cc[i + 1 - j]] += f[i][j][k] * (n - i - k - cc[i + 1 - j]);
    //             }
    //         }
    // }
    // mod rs = 0;
    // for (int j = m; j <= n; ++j)
    //     rs += f[n][j][0];
    // cout << rs << endl;
    // mod prd = 1;
    // for (int i = 1; i <= n; ++i){
    //     mod ss = 0;
    //     for (int j = 0; j <= i; ++j)
    //         for (int k = 0; k <= n; ++k)ss += f[i][j][k];
    //     prd = prd * (n - i + 1);
    //     clog << i << ":" << prd << "<->" << ss << endl;
    // }
    return 0;
}