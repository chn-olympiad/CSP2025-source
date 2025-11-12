#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
    int s[5], m, p;
    bool operator<(node b) const {
        return s[m] - s[p] > b.s[b.m] - b.s[b.p];
    }
};
node a[100005];
int k[5], q;
int ans;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t; cin >> t;
    while(t--) {
        cin >> n, ans = k[1] = k[2] = k[3] = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i].s[1] >> a[i].s[2] >> a[i].s[3];
            if(a[i].s[1] > a[i].s[2] && a[i].s[1] > a[i].s[3]) {
                a[i].m = 1;
                if(a[i].s[2] > a[i].s[3]) a[i].p = 2;
                else a[i].p = 3;
            } else if(a[i].s[2] > a[i].s[3]) {
                a[i].m = 2;
                if(a[i].s[1] > a[i].s[3]) a[i].p = 1;
                else a[i].p = 3;
            } else {
                a[i].m = 3;
                if(a[i].s[1] > a[i].s[2]) a[i].p = 1;
                else a[i].p = 2;
            }
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; ++i) {
            if(k[a[i].m] == n / 2) q = a[i].p;
            else q = a[i].m;
            ans += a[i].s[q], ++k[q];
        }
        cout << ans << '\n';
    }
    return 0;
}
