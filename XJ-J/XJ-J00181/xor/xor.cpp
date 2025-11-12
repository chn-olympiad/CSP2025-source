#include <iostream>
#include <cstring>
//haihaihai_Long_Live_the_People's_Republic_of_China!!!
#define mid (l + r >> 1)
using std::cin;
using std::cout;
inline int max(int p, int q){
    return p > q ? p : q;
}

const int N = 5e5 + 5;
int n, k, a[N];
int sum[N], ans;
int maxv[1 << 22], max_;

void update(int x, int l, int r, int u, int w){
    if (l == u && u == r){
        maxv[x] = max(maxv[x], w);
        return;
    }
    if (u <= mid)
        update(x << 1, l, mid, u, w);
    else
        update(x << 1|1, mid + 1, r, u, w);
    maxv[x] = max(maxv[x << 1], maxv[x << 1|1]);
}

int query(int x, int l, int r, int u){
    if (l == u && u == r)
        return maxv[x];
    if (u <= mid)
        return query(x << 1, l, mid, u);
    else
        return query(x << 1|1, mid + 1, r, u);
}

signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    std::memset(maxv, -0x3f, sizeof maxv);
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i - 1] ^ a[i], max_ = max(max_, sum[i]);
    update(1, 0, max_, 0, 0);
    for (int i = 1; i <= n; i++){
        ans = max(ans, query(1, 0, max_, sum[i] ^ k) + 1);
        update(1, 0, max_, sum[i], ans);
    }
    cout << ans << '\n';
}