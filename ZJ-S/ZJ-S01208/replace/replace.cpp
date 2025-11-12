#include<bits/stdc++.h>
using namespace std; 

namespace Main {

#define ld long double
#define all(x) begin(x), end(x) 
#define rep(i, l, r) for(int i(l), END##i(r); i <= END##i; ++ i) 
#define per(i, r, l) for(int i(r), END##i(l); i >= END##i; -- i) 

template<class T>
inline void cmax(T& x, const T& y) { x = max(x, y); }
template<class T>
inline void cmin(T& x, const T& y) { x = min(x, y); }

const int N = 1e5 + 10, M = 2.5e6 + 10; 

int n, Q; 
char basic_s[2][M * 3]; 
int len[N]; 
char *s[N][2];

vector<int>kmp[N][2]; 
void deal(int i) {
    rep(r, 0, 1) {
        char *str = s[i][r]; 
        vector<int>& nxt = kmp[i][r]; 
        nxt.resize(len[i] + 1); 
        int p = 0; 
        rep(j, 2, len[i]) {
            while (p && (str[p + 1] ^ str[j])) 
                p = nxt[p]; 
            if (str[p + 1] == str[j]) ++ p; 
            nxt[j] = p; 
        }
    }
}

int siz; 
char t[2][M]; 
void solve() {
    // fprintf (stderr, "#0\n");
    scanf ("%s%s", t[0] + 1, t[1] + 1); 
    siz = strlen(t[0] + 1); 
    int L = siz + 1, R = 0; 
    rep(i, 1, siz) 
        if (t[0][i] ^ t[1][i]) 
            cmin(L, i), cmax(R, i); 

    int cnt = 0; 
    rep(i, 1, n) {
        // fprintf (stderr, "# %d\n", i);
        int p[2] = { 0, 0 }; 
        char *str[2] = { s[i][0], s[i][1] };
        // vector<int>& nxt[2] = { kmp[i][0], kmp[i][1] }; 
        rep(j, 1, siz) {
            rep(r, 0, 1) {
                while (p[r] && (str[r][p[r] + 1] ^ t[r][j])) 
                    p[r] = kmp[i][r][p[r]]; 
                if (str[r][p[r] + 1] == t[r][j]) ++ p[r]; 
            } 
            if (p[0] == len[i] && p[1] == len[i]) {
                if (j - len[i] + 1 <= L && j >= R) 
                    ++ cnt; 
            } 
        } 
    }

    printf ("%d\n", cnt); 
}

void ERoRain() {
    scanf ("%d%d", &n, &Q); 
    int idxs[2] = { 0, 0 }; 
    rep(i, 1, n) {
        rep(r, 0, 1) {
            s[i][r] = basic_s[r] + idxs[r]; 
            scanf ("%s", s[i][r] + 1); 
            len[i] = strlen(s[i][r] + 1); 
            idxs[r] += len[i] + 2; 
        }
        deal(i); 
    } 
    while (Q --) solve(); 
}

signed main() {
    ld start_time = clock(); 
    int T = 1; 
    while (T --) ERoRain(); 
    fprintf (stderr, "Time : %Lf\n", (clock() - start_time) / CLOCKS_PER_SEC); 
    return 0; 
}

} signed main() {
    freopen("replace.in", "r", stdin); 
    freopen("replace.out", "w", stdout); 
    Main::main(); 
    return 0; 
}