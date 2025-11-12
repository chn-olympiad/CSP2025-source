#if defined(DEBUG) && !defined(_GLIBCXX_DEBUG)
#define _GLIBCXX_DEBUG
#endif

#define IO_FILE_NAME "replace"
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

constexpr ui MAXN = 2e5 + 5, MAXL = 5e6 + 5;
ui N, Q;
array<ui, MAXN> sz;
string s, t;

struct ACNode {
    array<ui, 26> ch;
    ui fail, h;
    ui& operator[](ui k) {
        return ch[k];
    }
};
struct ListNode {
    ui p, v;
};
array<ACNode, MAXL> ac;
array<ListNode, MAXN> ln;
ui tot = 2, lntot = 0, etot;
queue<ui> q;

array<ui, MAXL> h, num, numr, n1, n2;
array<ListNode, MAXL> e;

void append(ui& h, ui v) {
    ln[++lntot] = ListNode{h, v};
    h = lntot;
}
void tree_append(ui& h, ui v) {
    e[++etot] = ListNode{h, v};
    h = etot;
}
ui insert(ui rt, ui i, const string& str) {
    ui v, p = rt;
    for (char c : str) {
        v = c - 'a';
        if (!ac[p][v]) {
            ac[p][v] = ++tot;
        }
        p = ac[p][v];
    }
    append(ac[p].h, i);
    return p;
}
void get_fail(ui rt) {
    ac[rt].fail = rt;
    for (ui i = 0; i < 26; ++i) {
        if (ac[rt][i]) {
            ac[ac[rt][i]].fail = rt;
            q.emplace(ac[rt][i]);
        } else {
            ac[rt][i] = rt;
        }
    }
    while (!q.empty()) {
        ui p = q.front();
        q.pop();
        tree_append(h[ac[p].fail], p);
        for (ui i = 0; i < 26; ++i) {
            if (ac[p][i]) {
                ac[ac[p][i]].fail = ac[ac[p].fail][i];
                q.emplace(ac[p][i]);
            } else {
                ac[p][i] = ac[ac[p].fail][i];
            }
        }
    }
}
ui dfn;
void dfs0(ui u) {
    num[u] = ++dfn;
    for (ui i = h[u]; i; i = e[i].p) {
        dfs0(e[i].v);
    }
    numr[u] = dfn;
}
bool special(const string& s) {
    return count(s.begin(), s.end(), 'b') == 1 && int(count(s.begin(), s.end(), 'a')) == int(s.size()) - 1;
}
void test_case() {
    s.reserve(MAXL);
    t.reserve(MAXL);
    cin >> N >> Q;
    ui arona = 0;
    for (ui i = 1; i <= N; ++i) {
        cin >> s >> t;
        n1[i] = insert(1, i, s);
        n2[i] = insert(2, i, t);
        sz[i] = ui(s.size());
    }
    get_fail(1);
    get_fail(2);
    dfs0(1);
    dfs0(2);
    vector<ui> e0, e1, e2;
    for (ui qi = 0; qi < Q; ++qi) {
        cin >> s >> t;
        if (s.size() != t.size()) {
            cout << "0\n";
            continue;
        }
        ui len = ui(s.size());
        ui pre = ui(mismatch(s.begin(), s.end(), t.begin(), t.end()).first - s.begin());
        ui suf = ui(mismatch(s.rbegin(), s.rend(), t.rbegin(), t.rend()).first - s.rbegin());
        ui p0 = 1, p1 = 2;
        e0.clear();
        e1.clear();
        e2.clear();
        u64 ans = 0;
        for (ui i = 0; i < len; ++i) {
            p0 = ac[p0][s[i] - 'a'];
            p1 = ac[p1][t[i] - 'a'];
            if (i >= len - suf - 1) {
                for (ui j = 1; j <= N; ++j) {
                    if (i + 1 - pre <= sz[j] && num[n1[j]] <= num[p0] && num[p0] <= numr[n1[j]] && num[n2[j]] <= num[p1] && num[p1] <= numr[n2[j]]) {
                        ++ans;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
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
//    cout << flush;
//    ldebug("end2\n");
}
