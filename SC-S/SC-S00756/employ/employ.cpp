#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

inline bool checkchar(char c) {
    return isspace(c) || c == EOF;
}

template<typename T>
T qread_templ() {
    T val = 0;
    char c; bool inv = false;
    while (!isdigit(c = getchar()));
    if (c == '-') {
        inv = true;
        c = getchar();
    }
    do val = (val << 1) + (val << 3) + (c - '0');
    while (isdigit(c = getchar()));
    return inv ? (-val) : val;
}
char qwrite_buf[50];
template<typename T>
void qwrite(T val) {
    if (val < 0) {
        putchar('-');
        val = -val;
    }
    if (val < 10) {
        putchar('0' + val);
        return;
    }
    int n = 0;
    while (val) {
        T d = val / 10;
        qwrite_buf[n++] = (char) (val - (d << 1) - (d << 3) + '0');
        val = d;
    }
    while (n--) {
        putchar(qwrite_buf[n]);
    }
}
inline int qread() {
    return qread_templ<int>();
}
int readstr(char *s) {
    int n = 0; char c;
    while (isspace(c = getchar()));
    do s[n++] = c; while (!checkchar(c = getchar()));
    s[n] = '\0';
    return n;
}
char getgood() {
    char c;
    while (isspace(c = getchar()));
    return c;
}

#define MAXN (500+4)
#define MODNUM (998244353ll)
#define mod(x) ((x) % MODNUM)
typedef long long i64;

int n, m;
bool s[MAXN];
int c[MAXN], all[MAXN];

signed main() {
#define FILENAME "employ"
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    n = qread();
    m = qread();
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        s[i] = getgood() == '1';
        tot += s[i] ? 1 : 0;
    }
    if (tot < m) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        c[i] = qread();
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] != 0) {
            ++cnt;
        }
    }
    if (cnt == 0) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        all[i] = i;
    }
    int ans = 0;
    do {
        int failed = 0;
        for (int i = 0; i < n; ++i) {
            int guy = all[i];
            if (s[i] == 0 || failed >= c[guy]) {
                ++failed;
            }
        }
        if (n - failed >= m) {
            ++ans;
        }
    } while (std::next_permutation(all, all + n));
    qwrite(ans);
    putchar('\n');

    fclose(stdin);
    fclose(stdout);
    return 0;
}