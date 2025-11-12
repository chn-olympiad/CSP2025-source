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

#define MAXN (100000+4)

int n;
int a[MAXN][3];
int mx[MAXN][3], diff[MAXN];
int cnt[3];
int sort[MAXN], sl;

bool compare(int x, int y) {
    return diff[x] < diff[y];
}

signed main() {
#define FILENAME "club"
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    int TCases = qread();
    while (TCases--) {
        n = qread();
        cnt[0] = cnt[1] = cnt[2] = 0;
        long long tot = 0;
        for (int i = 0; i < n; ++i) {
            a[i][0] = qread();
            a[i][1] = qread();
            a[i][2] = qread();
            mx[i][0] = 0;
            mx[i][1] = 1;
            mx[i][2] = 2;
            std::sort(mx[i], mx[i] + 3, [i](int l, int r){ return a[i][l] < a[i][r]; });
            ++cnt[mx[i][2]];
            tot += a[i][mx[i][2]];
            diff[i] = a[i][mx[i][2]] - a[i][mx[i][1]];
        }
        int piv = -1, half = n / 2;
        if (cnt[0] > half) piv = 0;
        if (cnt[1] > half) piv = 1;
        if (cnt[2] > half) piv = 2;
        sl = 0;
        if (piv != -1) {
            for (int i = 0; i < n; ++i) {
                if (mx[i][2] == piv) {
                    sort[sl++] = i;
                }
            }
            std::sort(sort, sort + sl, compare);
            int i = 0;
            while (cnt[piv] > half) {
                tot -= diff[sort[i]];
                --cnt[piv];
                ++i;
            }
        }
        qwrite(tot);
        putchar('\n');
    }
    

    fclose(stdin);
    fclose(stdout);
    return 0;
}