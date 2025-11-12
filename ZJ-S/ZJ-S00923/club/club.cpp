#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
typedef pair<int, int> PP;
typedef double db;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n;
struct node {
    int x, y, z;
} a[N];
set<PP> s[4];
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    // freopen("club/club5.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    int T; cin >> T; while(T --) {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i ++) scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
        for(int i = 1; i <= 3; i ++) s[i].clear();
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            if(a[i].x >= a[i].y && a[i].x >= a[i].z) {
                ans += a[i].x;
                s[1].insert({a[i].x - max(a[i].y, a[i].z), i});
            }else if(a[i].y >= a[i].x && a[i].y >= a[i].z) {
                ans += a[i].y;
                s[2].insert({a[i].y - max(a[i].x, a[i].z), i});
            }else if(a[i].z >= a[i].x && a[i].z >= a[i].y) {
                ans += a[i].z;
                s[3].insert({a[i].z - max(a[i].y, a[i].x), i});
            }
        }
        for(int i = 1; i <= 3; i ++) {
            while(s[i].size() > (n / 2)) {
                PP x = *s[i].begin();
                s[i].erase(s[i].begin());
                ans -= x.x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}