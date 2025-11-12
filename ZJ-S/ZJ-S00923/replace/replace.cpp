#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull unsigned long long
#define x first
#define y second
typedef pair<int, int> PP;
typedef pair<string, string> PS;
typedef pair<ull, ull> PU;
typedef double db;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int P = 13331;
PS a[N], b[N];
PU a1[N];
    ull findval(string x) {
        ull ret = 0; int len = x.size() - 1;
        for(int i = 1; i <= len; i ++) ret *= P, ret += x[i];
        return ret;
    }
int n, Q;

namespace celinia1 {
    string t1, t2;
    ull ha1[N], ha2[N], mi[N];
    void findval1() {
        int len = t1.size() - 1;
        for(int i = 1; i <= len; i ++) ha1[i] = P * ha1[i - 1] + t1[i];
    }
    void findval2() {
        int len = t2.size() - 1;
        for(int i = 1; i <= len; i ++) ha2[i] = P * ha2[i - 1] + t2[i];
    }
    ull val1(int l, int r) {
        return ha1[r] - ha1[l - 1] * mi[r - l + 1];
    }
    ull val2(int l, int r) {
        return ha2[r] - ha2[l - 1] * mi[r - l + 1];
    }
    void solve() {
        mi[0] = 1;
        for(int i = 1; i <= 100000; i ++) mi[i] = mi[i - 1] * P;
        for(int C = 1; C <= Q; C ++) {
            t1 = b[C].x, t2 = b[C].y;
            if(t1.size() != t2.size()) {cout << 0 << '\n'; continue;}
            int len1 = 0, len2 = 0, len = t1.size() - 1;
            for(int i = 1; i <= len; i ++) { 
                if(t1[i] != t2[i]) break;
                len1 = i;
            }
            for(int i = len; i >= 1; i --) {
                if(t1[i] != t2[i]) break;
                len2 = len - i + 1;
            }
            findval1(), findval2();
            // cout << ha2[len] << ' ' << a1[1].y << endl;
            int ans = 0;
            for(int i = 0; i <= len1; i ++) {
                for(int j = 1; j <= n; j ++) {
                    if(i + a[j].x.size() - 1 > len) continue;
                    if(i + a[j].x.size() - 1 < len - len2) continue;
                    int len3 = len - (i + a[j].x.size() - 1);
                    int len4 = a[j].x.size() - 1;
                    if(a1[j].x == val1(i + 1, i + len4) && a1[j].y == val2(i + 1, i + len4)) ans ++;
                }
            }
            cout << ans << endl;
        }
    }
}
bool check(string x) {
    int len = x.size() - 1;
    int cnt = 0;
    for(int i = 1; i <= len; i ++) {
        if(x[i] != 'a' && x[i] != 'b') return 0;
        if(x[i] == 'b') cnt ++;
    }
    if(cnt != 1) return 0;
    return 1;
}
namespace celinia2 {
    map<int, int> mm;
    int tot;
    int findpair(string x) {
        int len = x.size() - 1;
        int len1 = 0, len2 = 0;
        for(int i = 1; i <= len; i ++) {
            if(x[i] != 'a') break;
            len1 = i;
        }
        return len1;
    }
    string t1, t2;
    vector<PP> v[N];
    int ans[N];
    void solve() {
        for(int i = 1; i <= n; i ++) {
            int now = findpair(a[i].x) - findpair(a[i].y);
            if(!mm[now]) mm[now] = ++tot;
            int len2 = a[i].x.size() - 1;
            v[mm[now]].push_back({min(findpair(a[i].x), findpair(a[i].y)), min(len2 - findpair(a[i].x) - 1, len2 - findpair(a[i].y) - 1)});
        }
        for(int i = 1; i <= tot; i ++) sort(v[i].begin(), v[i].end());
        for(int C = 1; C <= Q; C ++) {
            t1 = b[C].x, t2 = b[C].y;
            if(t1.size() != t2.size()) {cout << 0 << endl; continue;}
            int now = findpair(t1) - findpair(t2);
            int len2 = t1.size() - 1;
            if(!mm.count(now)) {cout << 0 << endl; continue;}
            int p = mm[now];
            int ans = 0;
            for(PP wasd : v[p]) {
                if(wasd.x >= max(findpair(b[C].x), findpair(b[C].y)) && wasd.y >= max(len2 - findpair(b[C].x) - 1, len2 - findpair(b[C].y) - 1)) ans ++;
            }
            cout << ans << endl;
        }
    }
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    // freopen("replace/replace2.in", "r", stdin);
    // freopen("C.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> Q;
    bool flg = 1;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].x >> a[i].y, a[i].x = " " + a[i].x, a[i].y = " " + a[i].y;
        a1[i] = {findval(a[i].x), findval(a[i].y)};
        flg &= check(a[i].x);
        flg &= check(a[i].y);
    }
    for(int i = 1; i <= Q; i ++) {
        cin >> b[i].x >> b[i].y, b[i].x = " " + b[i].x, b[i].y = " " + b[i].y;
        flg &= check(b[i].x);
        flg &= check(b[i].y);
    }
    // cout << flg << endl;
    if(n <= 1000) celinia1::solve();
    else if(flg) celinia2::solve();
    return 0;
}