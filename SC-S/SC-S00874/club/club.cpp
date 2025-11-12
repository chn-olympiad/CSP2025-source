#include <cstdio>
#include <algorithm>
using namespace std;
struct IO {
    IO () {
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;
const int N = 1e5 + 5;
int n, cnt[4], sum[4];
struct Node {
    int val, clb;
    bool operator < (const Node &rhs) const {
        return val > rhs.val;
    }
} ;
struct Item {
    int cnt;
    Node a[4];
    bool operator < (const Item &rhs) const {
        if (cnt != rhs.cnt) return cnt < rhs.cnt;
        if (a[1].val + rhs.a[2].val != a[2].val + rhs.a[1].val)
            return a[1].val + rhs.a[2].val > a[2].val + rhs.a[1].val;
        return a[3] < rhs.a[3];
    }
} e[N];
void clear () {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 3; j++)
            e[i].a[j] = {0, 0};
    cnt[1] = cnt[2] = cnt[3] = 0;
    sum[1] = sum[2] = sum[3] = 0;
}
void solve () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            scanf("%d", &e[i].a[j].val);
            e[i].a[j].clb = j;
            if (e[i].a[j].val) e[i].cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
        sort(e[i].a + 1, e[i].a + 4);
    sort(e + 1, e + n + 1);
    // for (int i = 1; i <= n; i++)
    //     printf("%d-%d %d-%d %d-%d\n", e[i].a[1].val, e[i].a[1].clb, e[i].a[2].val, e[i].a[2].clb, e[i].a[3].val, e[i].a[3].clb);
    for (int i = 1; i <= n; i++) {
        int clb = e[i].a[1].clb;
        int val = e[i].a[1].val;
        if (cnt[clb] < (n >> 1)) {
            sum[clb] += val;
            ++cnt[clb];
        } else {
            sum[e[i].a[2].clb] += e[i].a[2].val;
            ++cnt[e[i].a[2].clb];
        }
    }
    int ans = 0;
    for (int i = 1; i <= 3; i++)
        ans += sum[i];
    printf("%d\n", ans);
    clear();
}
int main () {
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}