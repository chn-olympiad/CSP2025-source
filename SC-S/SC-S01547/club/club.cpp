// Go in my style.
// Not afraid to dark.
// Beat.

#include <bits/stdc++.h>
using namespace std;

namespace io {
    int pos;
    inline int read(int &p = pos) {
        static int v; static char c;
        p = 0, v = 1, c = getchar();
        while (!isdigit(c)) {
            if (c == '-') v = -1;
            c = getchar();
        }
        while (isdigit(c)) {
            p = (p << 1) + (p << 3) + (c - 48);
            c = getchar();
        }
        return p = v == 1 ? p : -p;
    }
    inline void write(int x) {
        static int sta[65], top;
        if (x < 0) x = -x, putchar('-');
        top = 0;
        do {
            sta[++top] = x % 10;
            x /= 10;
        } while(x);
        while (top) putchar(sta[top--] + 48);
    }
}

const int N = 1e5;
int n, a[N + 5][3], mxi[N + 5];

int b[N + 5];

inline void ARKNIGHTS() {
    io::read(n);
    array<int, 3> cnt = {0, 0, 0};
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
        int mx = 0;
        for (int j = 0; j < 3; ++j) {
            io::read(a[i][j]);
            mx = max(mx, a[i][j]);
        }
        tmp += mx;
        for (int j = 0; j < 3; ++j)
            if (mx == a[i][j]) {
                ++cnt[j];
                mxi[i] = j;
                break;
            }
    }
    if (max(cnt[0], max(cnt[1], cnt[2])) <= n / 2) io::write(tmp), putchar('\n');
    else {
        int ans = 0;
        for (int o = 0; o < 3; ++o) {
            tmp = 0;
            for (int i = 1; i <= n; ++i) b[i] = max(a[i][(o + 1) % 3], a[i][(o + 2) % 3]) - a[i][o], tmp += a[i][o];
            sort(b + 1, b + n + 1, [](const int x, const int y) { return x > y; });
            for (int i = 1; i <= n / 2; ++i) tmp += b[i];
            ans = max(ans, tmp);
        }
        io::write(ans), putchar('\n');
    }
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    for (int T = io::read(); T--; ARKNIGHTS()) ;
    return 0;
}