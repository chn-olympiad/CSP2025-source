#if defined(DEBUG) && !defined(_GLIBCXX_DEBUG)
#define _GLIBCXX_DEBUG
#endif

#define IO_FILE_NAME "club"
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

template <typename T, typename U>
bool ckmax(T& a, const U& b) {
    return a < b && (a = b, true);
}
template <typename T, typename U>
bool ckmin(T& a, const U& b) {
    return b < a && (a = b, true);
}


/*
分配到 A 部门可以获得 a[i] 收益 
分配到 B 部门可以获得 b[i] 收益
或者不分配
一个部门最多分配 N/2 人
最少分配 N/2 人

我肯定可以把 max(a, b) 最大的 N/2 个人分配出去，并且已经满足条件。剩下的:
先把他分配到更优的部门。如果超员，就踢一个去另一个部门。这不会造成另一个部门超员。
*/

constexpr ui MAXN = 1e5 + 5;
ui N;
int ans;
struct Person {
    int a, b;
    bool operator<(const Person& o) const {
        return max(a, b) > max(o.a, o.b);
    }
};
array<Person, MAXN> p;
priority_queue<int> pa, pb; // 扔掉它可以获得 first 价值，扔掉是指扔到对面 / 直接丢弃

void test_case() {
    cin >> N;
    ldebug("case N=%u\n", N);
    ans = 0;
    while (!pa.empty()) {
        pa.pop();
    }
    while (!pb.empty()) {
        pb.pop();
    }
    int a, b, c;
    for (ui i = 1; i <= N; ++i) {
        cin >> a >> b >> c;
        p[i].a = b - a;
        p[i].b = c - a;
        ans += a;
    }
    ldebug("A\n");
//    ldebug("now ans=%d\n", ans);
    sort(p.begin() + 1, p.begin() + N + 1);
    for (ui i = 1; i <= N / 2; ++i) {
        if (p[i].a >= p[i].b) {
            ans += p[i].a;
//            ldebug("a1 ans += %d\n", p[i].a);
            pa.emplace(max(p[i].b, 0) - p[i].a);
        } else {
            ans += p[i].b;
//            ldebug("b1 ans += %d\n", p[i].b);
            pb.emplace(max(p[i].a, 0) - p[i].b);
        }
    }
//    ldebug("now ans=%d\n", ans);
    for (ui i = N / 2 + 1; i <= N; ++i) {
        if (max(p[i].a, p[i].b) <= 0) {
            break;
        }
        if (p[i].a >= p[i].b) {
//            ldebug("a2 ans += %d\n", p[i].a);
            ans += p[i].a;
            pa.emplace(max(p[i].b, 0) - p[i].a);
        } else {
            ans += p[i].b;
//            ldebug("b2 ans += %d\n", p[i].b);
            pb.emplace(max(p[i].a, 0) - p[i].b);
        }
    }
    while (pa.size() > N / 2) {
//        ldebug("a ans -= %d\n", -pa.top());
        ans += pa.top();
        pa.pop();
    }
    while (pb.size() > N / 2) {
//        ldebug("b ans -= %d\n", -pb.top());
        ans += pb.top();
        pb.pop();
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
    cin >> T;
    for (ui ca = 1; ca <= T; ++ca) {
        test_case();
    }
}
