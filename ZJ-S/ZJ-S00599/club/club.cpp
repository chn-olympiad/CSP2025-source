#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct man {int aa, bb, cc;}a[N];
bool cmp1(man x, man y) {return x.aa > y.aa;}
bool cmp2(man x, man y) {return x.aa-x.bb < y.aa-y.bb;}
bool cmp3(man x, man y) {return x.bb-x.aa < y.bb-y.aa;}
bool A = true, B = true;
int t, n;
int one, two, thr;
int res, mmax = INT_MIN;
int ks = 0; 
void dfs(int x) {
    if (one > n / 2 || two > n / 2 || thr > n / 2) {return;}
    if (x == n + 1) {mmax = max(mmax, res);return;}
    res += a[x].aa;one++;
    dfs(x+1);
    one--;res -= a[x].aa;res += a[x].bb;two++;
    dfs(x+1);
    two--;res -= a[x].bb;res += a[x].cc;thr++;
    dfs(x+1);
    thr--;res -= a[x].cc;
}
void solv1() {
    mmax = INT_MIN, res = 0;
    dfs(1);
    cout << mmax << '\n';
}
void solv2() {
    sort(a+1, a+n+1, cmp1);
    res = 0;
    for (int i = 1; i <= n/2; ++i) res += a[i].aa;
    cout << res << '\n';
}
void solv3() {
    int an = 0;
    res = 0;
    vector<int> ac, bc;
    for (int i = 1; i <= n; ++i) {
        if (a[i].aa > a[i].bb) {
            an ++;
            res += a[i].aa;
            ac.push_back(a[i].aa - a[i].bb);
        } else {
            res += a[i].bb;
            bc.push_back(-a[i].aa + a[i].bb);
        }
    }
    int bn = n - an;
    if (an > n/2) {
        int tmp = an - n/2;
        sort(ac.begin(), ac.end());
        for (int i = 0; i < tmp; i ++) {
            res -= ac[i];
        }
        cout << res << '\n';
    } else if (an == n/2) cout << res << '\n';
    else {
        int tmp = bn - n/2;
        sort(bc.begin(), bc.end());
        for (int i = 0; i < tmp; i ++) {
            res -= bc[i];
        }
        cout << res << '\n';
    }
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].aa >> a[i].bb >> a[i].cc;
            if (a[i].cc) {
                A = false;
                B = false;
            }
            if (a[i].bb) {
                A = false;
            }
        }
        if (n <= 30) {
            solv1();
        } else if (A) {
            solv2();
        } else if (B) {
            solv3();
        }
    }
    return 0;
}