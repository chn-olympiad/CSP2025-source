#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, TN = 35;
struct dat{int a, b, c;}s[N];
int n, ans;
bool cmp(dat a, dat b){
    return a.a > b.a;
}
void dfs(int i, int cnt, int a, int b, int c){
    if (a > n / 2) return;
    if (b > n / 2) return;
    if (c > n / 2) return;
    if (i > n){
        //cout << a << ' ' << b << ' ' << c << ' ' << ans << '\n';
        ans = max(cnt, ans);
    }
    dfs(i + 1, cnt + s[i].a, a + 1, b, c);
    dfs(i + 1, cnt + s[i].b, a, b + 1, c);
    dfs(i + 1, cnt + s[i].c, a, b, c + 1);
}
void solve(){
    memset(s, 0, sizeof s);
    cin >> n;
    int cnt = 0;
    for (int i = 1;i <= n;i ++){
        cin >> s[i].a >> s[i].b >> s[i].c;
        if (s[i].b == 0 && s[i].c == 0){
            cnt ++;
        }
    }
    if (cnt == n){
        int ans = 0;
        sort(s + 1, s + 1 + n, cmp);
        for (int i = 1;i <= n / 2;i ++){
            ans += s[i].a;
        }
        cout << ans;
        return;
    }
    else{
        ans = 0;
        dfs(1, 0, 0, 0, 0);
        cout << ans << '\n';
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}
