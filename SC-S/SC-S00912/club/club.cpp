/* start club */
#include<bits/stdc++.h>
#define fup(i, bg, ed) for(int i = (bg); i <= (ed); i++)
#define fdn(i, bg, ed) for(int i = (bg); i >= (ed); i--)
typedef long long lld;
using namespace std;

struct AutoIO {
    AutoIO() {
        freopen("club.in", "r", stdin);
        freopen("club.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    ~AutoIO() {
        cout.flush();
        #ifdef Local
        cerr << 1. * clock() / CLOCKS_PER_SEC << "ms" << "\n";
        #endif
    }
}__cdl_auto_io;

const int N = 1e5 + 10;

int T, n;
int cnt[3];

struct Item {
    int a, b, c;
    int mx, smx, tp;
    void build() {
        mx = a;
        if(b > mx) smx = mx, mx = b;
        else smx = max(smx, b);
        if(c > mx) smx = mx, mx = c;
        else smx = max(smx, c);
        if(mx == a) tp = 0;
        else if(mx == b) tp = 1;
        else if(mx == c) tp = 2;
    }
}it[N];

void slv() { 
    fup(i, 0, 2) cnt[i] = 0;
    fup(i, 1, n) it[i] = { 0, 0, 0, 0, 0, -1 };
    cin >> n;
    fup(i, 1, n) cin >> it[i].a >> it[i].b >> it[i].c, it[i].build();
    sort(it + 1, it + n + 1, [](Item l, Item r) {
        return l.mx - l.smx < r.mx - r.smx;
    });
    lld ans = 0;
    fup(i, 1, n) cnt[it[i].tp]++, ans += it[i].mx;
    int mxtp = 0;
    fup(i, 0, 2) if(cnt[i] > cnt[mxtp]) mxtp = i;
    int i = 1;
    // cerr << cnt[mxtp] << "\n";
    // cerr << ans << endl;
    // fup(i, 1, n) cerr << it[i].mx - it[i].smx << " \n"[i==n];
    while(cnt[mxtp] > n / 2) {
        if(it[i].tp == mxtp) ans -= it[i].mx - it[i].smx, --cnt[mxtp];
        ++i;
    }
    cout << ans << "\n";
}

main() {
    cin >> T;
    fup(tc, 1, T) slv();
}

/* end club */