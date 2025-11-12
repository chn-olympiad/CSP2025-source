#if defined(DEBUG) && !defined(_GLIBCXX_DEBUG)
#define _GLIBCXX_DEBUG
#endif

#define IO_FILE_NAME "road"
#define LOCAL_FILE_IO

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
using PII = pair<ui, ui>;

template <typename T, typename U>
bool ckmax(T& a, const U& b) {
    return a < b && (a = b, true);
}
template <typename T, typename U>
bool ckmin(T& a, const U& b) {
    return b < a && (a = b, true);
}

void read_ui(ui& r) {
    static ui c;
    c = getchar();
    while (c < 48) {
        c = getchar();
    }
    r = c & 15;
    c = getchar();
    while (c >= 48) {
        r = r * 10  + (c & 15);
        c = getchar();
    }
}

constexpr ui MAXN = 1e4 + 5, MAXM = 1e6 + 5, MAXK = 15;
ui N, M, K;
array<ui, MAXK> c;
u64 ans, sum;
struct Edge {
    ui u, v, w;
    bool operator<(const Edge& o) const {
        return w < o.w;
    }
};
array<Edge, MAXM> e;
array<array<Edge, MAXN>, MAXK> a;
array<ui, MAXN + MAXK> fr;
array<ui, MAXK> done, ecnt;
priority_queue<PII, vector<PII>, greater<PII>> pq;

ui fd(ui k) {
    while (fr[k] != k) {
        k = fr[k] = fr[fr[k]];
    }
    return k;
}
void unn(ui u, ui v) {
    fr[fd(u)] = fd(v);
}
void add_edge(const Edge& e) {
    if (fd(e.u) != fd(e.v)) {
        unn(e.u, e.v);
        sum += e.w;
    }
}
void test_case() {
    read_ui(N);
    read_ui(M);
    read_ui(K);
//    cin >> N >> M >> K;
    for (ui i = 1; i <= M; ++i) {
        read_ui(e[i].u);
        read_ui(e[i].v);
        read_ui(e[i].w);
//        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e.begin() + 1, e.begin() + M + 1);
    iota(fr.begin() + 1, fr.begin() + N + 1, 1U);
    for (ui i = 1; i <= M; ++i) {
        if (fd(e[i].u) != fd(e[i].v)) {
            unn(e[i].u, e[i].v);
            a[K][++ecnt[K]] = e[i];
        }
    }
    for (ui i = 0; i < K; ++i) {
        read_ui(c[i]);
//        cin >> c[i];
        ecnt[i] = N;
        for (ui j = 1, v; j <= N; ++j) {
            read_ui(v);
//            cin >> v;
            a[i][j].u = j;
            a[i][j].v = N + i + 1;
            a[i][j].w = v;
        }
        sort(a[i].begin() + 1, a[i].begin() + N + 1);
    }
    ans = ULLONG_MAX;
    for (ui S = 0; S < (1U << K); ++S) {
        iota(fr.begin() + 1, fr.begin() + N + K + 1, 1U);
        sum = 0;
        pq.emplace(e[1].w, K);
        fill_n(done.begin(), K + 1, 1U);
        for (ui i = 0; i < K; ++i) {
            if (S >> i & 1) {
                sum += c[i];
                pq.emplace(a[i][1].w, i);
            }
        }
        while (!pq.empty()) {
            ui i = pq.top().second;
            pq.pop();
            add_edge(a[i][done[i]]);
            if (done[i] < ecnt[i]) {
                ++done[i];
                pq.emplace(a[i][done[i]].w, i);
            }
        }
        ckmin(ans, sum);
    }
    cout << ans << '\n';
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
