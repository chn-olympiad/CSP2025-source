#include<bits/stdc++.h>
#define rep(i, r) for(int i = 1; i <= r; i++)
#define Rep(i, l, r) for(int i = l; i <= r; i++)
#define lep(i, r) for(int i = r; i; i--)
#define Lep(i, l, r) for(int i = r; i >= l; i--)
using namespace std;
const int N = 5e6 + 5, M = 2e5 + 5, P = 13331;
//const int N = 5 + 5, M = 5 + 5, P = 13331;
using ull = unsigned long long;
int n, q;
char s1[N], s2[N];
ull p[N], a[N], b[N];
struct node {
    ull a, b;
    int len;
};
vector<node> h[26][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    p[0] = 1;
    rep(i, N - 5) p[i] = p[i - 1] * 13331;
    rep(i, n) {
        cin >> s1 + 1 >> s2 + 1;
        int len = strlen(s1 + 1);
        ull x = 0, y = 0;
        rep(i, len) x = x * P + s1[i], y = y * P + s2[i];
        h[s1[1] - 'a'][s2[1] - 'a'].push_back({x, y, len});
    }
    while(q--) {
        cin >> s1 + 1 >> s2 + 1;
        int len = strlen(s1 + 1), l2 = strlen(s2 + 1);
        if(len != l2) {
            cout << "0\n";
            continue;
        }
        rep(i, len) a[i] = a[i - 1] * P + s1[i], b[i] = b[i - 1] * P + s2[i];
        int l = 1, r = len;
        while(l <= r) {
            int mid = l + r >> 1;
            if(a[mid] == b[mid]) l = mid + 1;
            else r = mid - 1;
        }
//        cerr << l << '\n';
        int cnt = 0;
        if(l == len + 1) {
            rep(j, len) {
                auto &h = ::h[s1[j] - 'a'][s2[j] - 'a'];
                for(int i = 0; i < h.size(); i++) {
                    int le = h[i].len;
                    if(j + le - 1 > len) continue;
                    if(a[j + le - 1] - a[j - 1] * p[le] == h[i].a && b[j + le - 1] - b[j - 1] * p[le] == h[i].b) cnt++;
                }
            }
        }
        else {
            rep(j, l) {
                auto &h = ::h[s1[j] - 'a'][s2[j] - 'a'];
                for(int i = 0; i < h.size(); i++) {
                    int le = h[i].len;
                    if(j + le - 1 > len) continue;
                    if(a[j + le - 1] - a[j - 1] * p[le] == h[i].a && b[j + le - 1] - b[j - 1] * p[le] == h[i].b
                        && a[len] - a[j + le - 1] * p[len - j - le + 1] == b[len] - b[j + le - 1] * p[len - j - le + 1]) cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
//chzx_lfw AK IOI!!!!!