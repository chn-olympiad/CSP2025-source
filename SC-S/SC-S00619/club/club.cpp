#include <queue>
#include <cstdio>
#include <algorithm>

const int N = 1e5 + 10;

struct Node {
    int val, id;
    bool operator < (const Node &rhs) const {
        return val < rhs.val;
    }
};

int n, a[N], b[N], c[N], choose[N], tot[5];

int solve() {

    int ans = 0;
    std :: priority_queue <Node> p, q, w, h;
    for (int i = 1; i <= n / 2; i ++) p.push({b[i] - a[i], i}), ans += a[i], choose[i] = 0, tot[0] ++; 
    for (int i = n / 2 + 1; i <= n; i ++) q.push({a[i] - b[i], i}), ans += b[i], choose[i] = 1, tot[1] ++;

    while (!q.empty()) {
        Node A = p.top(), B = q.top();
        p.pop(), q.pop();
        if (ans < ans + A.val + B.val) ans = ans + A.val + B.val, choose[A.id] ^= 1, choose[B.id] ^= 1;
        else break;
    }

    for (int i = 1; i <= n; i ++) {
        int val;
        if (choose[i] == 0) val = c[i] - a[i];
        else val = c[i] - b[i];
        w.push({val, i});
    }

    while (!w.empty()) {
        Node x = w.top();
        w.pop();
        if (ans < ans + x.val && tot[2] < n / 2) ans = ans + x.val, tot[choose[x.id]] --, choose[x.id] = 2, tot[2] ++;
    }

    for (int i = 1; i <= n; i ++) {
        if (!choose[i]) h.push({b[i] - a[i], i});
        if (choose[i] == 1) h.push({a[i] - b[i], i});
    }

    while (!h.empty()) {
        Node x = h.top();
        h.pop();
        if (tot[choose[x.id] ^ 1] < n / 2 && ans <= ans + x.val) ans = ans + x.val, tot[choose[x.id] ^ 1] ++, tot[choose[x.id]] --, choose[x.id] ^= 1;
    }

    tot[0] = tot[1] = tot[2] = 0;

    return ans;
}

void read(int &p) {
    p = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') p = (p << 3) + (p << 1) + c - '0', c = getchar();
    return ;
}

int main() {

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    read(T);
    while (T --) {
        read(n);
        for (int i = 1; i <= n; i ++) read(a[i]), read(b[i]), read(c[i]);
        printf("%d\n", solve());
    }

    return 0;
}